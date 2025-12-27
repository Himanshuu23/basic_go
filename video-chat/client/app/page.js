'use client';

import React, { useState, useEffect, useRef } from 'react';
import { Video, Mic, MicOff, VideoOff, PhoneOff, VideoOffIcon } from 'lucide-react';

export default function Home() {
  const [roomId, setRoomId] = useState('');
  const [joined, setJoined] = useState(false);
  const [userId] = useState(() => Math.random().toString(36).substr(2, 9));
  const [audioEnabled, setAudioEnabled] = useState(true);
  const [videoEnabled, setVideoEnabled] = useState(true);
  const [hasMediaAccess, setHasMediaAccess] = useState(true);
  
  const wsRef = useRef(null);
  const localStreamRef = useRef(null);
  const localVideoRef = useRef(null);
  const peerConnectionsRef = useRef({});
  const [remoteUsers, setRemoteUsers] = useState([]);

  const config = {
    iceServers: [
      { urls: 'stun:stun.l.google.com:19302' },
      { urls: 'stun:stun1.l.google.com:19302' }
    ]
  };

  useEffect(() => {
    return () => {
      cleanup();
    };
  }, []);

  const cleanup = () => {
    if (localStreamRef.current) {
      localStreamRef.current.getTracks().forEach(track => track.stop());
    }
    Object.values(peerConnectionsRef.current).forEach(pc => pc.close());
    if (wsRef.current) {
      wsRef.current.close();
    }
  };

  const joinRoom = async () => {
    if (!roomId.trim()) return;

    try {
      const stream = await navigator.mediaDevices.getUserMedia({
        video: true,
        audio: true
      });
      
      localStreamRef.current = stream;
      setHasMediaAccess(true);
      
      setTimeout(() => {
        if (localVideoRef.current && stream) {
          localVideoRef.current.srcObject = stream;
        }
      }, 100);
    } catch (error) {
      console.error('Error accessing media devices:', error);
      setHasMediaAccess(false);
      setVideoEnabled(false);
      setAudioEnabled(false);
    }

    const ws = new WebSocket(process.env.NEXT_PUBLIC_WS_URL);
    wsRef.current = ws;

    ws.onopen = () => {
      ws.send(JSON.stringify({
        type: 'join',
        from: userId,
        room: roomId
      }));
      setJoined(true);
    };

    ws.onmessage = async (event) => {
      const message = JSON.parse(event.data);

      switch (message.type) {
        case 'users':
          console.log('Existing users in room:', message.users);
          for (const user of message.users) {
            await createPeerConnection(user, true);
          }
          break;

        case 'user-joined':
          console.log('User joined:', message.from);
          await createPeerConnection(message.from, false);
          break;

        case 'offer':
          await handleOffer(message);
          break;

        case 'answer':
          await handleAnswer(message);
          break;

        case 'ice-candidate':
          await handleIceCandidate(message);
          break;

        case 'user-left':
          console.log('User left:', message.from);
          handleUserLeft(message.from);
          break;
      }
    };

    ws.onerror = (error) => {
      console.error('WebSocket error:', error);
    };

    ws.onclose = () => {
      console.log('WebSocket closed');
    };
  };

  const createPeerConnection = async (remoteUserId, createOffer) => {
    console.log('Creating peer connection with:', remoteUserId, 'isOffer:', createOffer);
    
    if (peerConnectionsRef.current[remoteUserId]) {
      console.log('Peer connection already exists for:', remoteUserId);
      return;
    }

    const pc = new RTCPeerConnection(config);
    peerConnectionsRef.current[remoteUserId] = pc;

    if (localStreamRef.current) {
      localStreamRef.current.getTracks().forEach(track => {
        pc.addTrack(track, localStreamRef.current);
      });
    }

    pc.ontrack = (event) => {
      console.log('Received track from:', remoteUserId);
      setRemoteUsers(prev => {
        const exists = prev.find(u => u.id === remoteUserId);
        if (!exists) {
          return [...prev, { id: remoteUserId, stream: event.streams[0] }];
        }
        return prev.map(u => 
          u.id === remoteUserId ? { ...u, stream: event.streams[0] } : u
        );
      });
    };

    pc.onicecandidate = (event) => {
      if (event.candidate && wsRef.current) {
        wsRef.current.send(JSON.stringify({
          type: 'ice-candidate',
          to: remoteUserId,
          payload: event.candidate
        }));
      }
    };

    pc.oniceconnectionstatechange = () => {
      console.log('ICE connection state with', remoteUserId, ':', pc.iceConnectionState);
    };

    if (createOffer) {
      try {
        const offer = await pc.createOffer();
        await pc.setLocalDescription(offer);
        wsRef.current.send(JSON.stringify({
          type: 'offer',
          to: remoteUserId,
          payload: offer
        }));
      } catch (error) {
        console.error('Error creating offer:', error);
      }
    }
  };

  const handleOffer = async (message) => {
    console.log('Received offer from:', message.from);
    
    if (!peerConnectionsRef.current[message.from]) {
      await createPeerConnection(message.from, false);
    }
    
    const pc = peerConnectionsRef.current[message.from];
    
    try {
      await pc.setRemoteDescription(new RTCSessionDescription(message.payload));
      const answer = await pc.createAnswer();
      await pc.setLocalDescription(answer);
      
      wsRef.current.send(JSON.stringify({
        type: 'answer',
        to: message.from,
        payload: answer
      }));
    } catch (error) {
      console.error('Error handling offer:', error);
    }
  };

  const handleAnswer = async (message) => {
    console.log('Received answer from:', message.from);
    const pc = peerConnectionsRef.current[message.from];
    if (pc) {
      try {
        await pc.setRemoteDescription(new RTCSessionDescription(message.payload));
      } catch (error) {
        console.error('Error handling answer:', error);
      }
    }
  };

  const handleIceCandidate = async (message) => {
    const pc = peerConnectionsRef.current[message.from];
    if (pc && pc.remoteDescription) {
      try {
        await pc.addIceCandidate(new RTCIceCandidate(message.payload));
      } catch (error) {
        console.error('Error adding ICE candidate:', error);
      }
    }
  };

  const handleUserLeft = (userId) => {
    if (peerConnectionsRef.current[userId]) {
      peerConnectionsRef.current[userId].close();
      delete peerConnectionsRef.current[userId];
    }
    setRemoteUsers(prev => prev.filter(u => u.id !== userId));
  };

  const toggleAudio = () => {
    if (localStreamRef.current) {
      const audioTrack = localStreamRef.current.getAudioTracks()[0];
      if (audioTrack) {
        audioTrack.enabled = !audioTrack.enabled;
        setAudioEnabled(audioTrack.enabled);
      }
    }
  };

  const toggleVideo = () => {
    if (localStreamRef.current) {
      const videoTrack = localStreamRef.current.getVideoTracks()[0];
      if (videoTrack) {
        videoTrack.enabled = !videoTrack.enabled;
        setVideoEnabled(videoTrack.enabled);
      }
    }
  };

  const leaveRoom = () => {
    cleanup();
    setJoined(false);
    setRemoteUsers([]);
    peerConnectionsRef.current = {};
  };

  const RemoteVideo = ({ user }) => {
    const videoRef = useRef(null);

    useEffect(() => {
      if (videoRef.current && user.stream) {
        videoRef.current.srcObject = user.stream;
      }
    }, [user.stream]);

    return (
      <div className="relative bg-gray-900 rounded-lg overflow-hidden">
        <video
          ref={videoRef}
          autoPlay
          playsInline
          className="w-full h-full object-cover"
        />
        <div className="absolute bottom-2 left-2 bg-black/50 px-2 py-1 rounded text-white text-sm">
          User {user.id.slice(0, 6)}
        </div>
      </div>
    );
  };

  if (!joined) {
    return (
      <div className="min-h-screen bg-gradient-to-br from-blue-500 to-purple-600 flex items-center justify-center p-4">
        <div className="bg-white rounded-2xl shadow-2xl p-8 w-full max-w-md">
          <div className="flex items-center justify-center mb-6">
            <Video className="w-12 h-12 text-blue-600" />
          </div>
          <h1 className="text-3xl font-bold text-center mb-2 text-gray-800">
            Video Chat
          </h1>
          <p className="text-center text-gray-600 mb-6">
            Enter a room name to start chatting
          </p>
          <input
            type="text"
            value={roomId}
            onChange={(e) => setRoomId(e.target.value)}
            placeholder="Room name"
            className="w-full px-4 py-3 border-2 border-gray-300 rounded-lg mb-4 focus:outline-none focus:border-blue-500 transition text-black"
            onKeyPress={(e) => e.key === 'Enter' && joinRoom()}
          />
          <button
            onClick={joinRoom}
            className="w-full bg-blue-600 hover:bg-blue-700 text-white font-semibold py-3 rounded-lg transition duration-200"
          >
            Join Room
          </button>
        </div>
      </div>
    );
  }

  return (
    <div className="min-h-screen bg-gray-900 p-4">
      <div className="max-w-7xl mx-auto">
        <div className="mb-4 flex justify-between items-center">
          <h2 className="text-white text-xl font-semibold">
            Room: {roomId}
          </h2>
          <div className="text-gray-400 text-sm">
            {remoteUsers.length} other user{remoteUsers.length !== 1 ? 's' : ''} connected
          </div>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-4 mb-4">
          <div className="relative bg-gray-800 rounded-lg overflow-hidden aspect-video">
            {hasMediaAccess ? (
              <video
                ref={localVideoRef}
                autoPlay
                muted
                playsInline
                className="w-full h-full object-cover"
              />
            ) : (
              <div className="w-full h-full flex items-center justify-center">
                <VideoOffIcon className="w-16 h-16 text-gray-500" />
              </div>
            )}
            <div className="absolute bottom-2 left-2 bg-black/50 px-2 py-1 rounded text-white text-sm flex items-center gap-2">
              You
              {!hasMediaAccess && (
                <VideoOffIcon className="w-4 h-4 text-red-500" />
              )}
            </div>
          </div>

          {remoteUsers.map(user => (
            <div key={user.id} className="aspect-video">
              <RemoteVideo user={user} />
            </div>
          ))}
        </div>

        <div className="flex justify-center gap-4">
          <button
            onClick={toggleAudio}
            disabled={!hasMediaAccess}
            className={`p-4 rounded-full ${
              !hasMediaAccess ? 'bg-gray-800 opacity-50 cursor-not-allowed' :
              audioEnabled ? 'bg-gray-700 hover:bg-gray-600' : 'bg-red-600 hover:bg-red-700'
            } transition`}
          >
            {audioEnabled ? (
              <Mic className="w-6 h-6 text-white" />
            ) : (
              <MicOff className="w-6 h-6 text-white" />
            )}
          </button>

          <button
            onClick={toggleVideo}
            disabled={!hasMediaAccess}
            className={`p-4 rounded-full ${
              !hasMediaAccess ? 'bg-gray-800 opacity-50 cursor-not-allowed' :
              videoEnabled ? 'bg-gray-700 hover:bg-gray-600' : 'bg-red-600 hover:bg-red-700'
            } transition`}
          >
            {videoEnabled ? (
              <Video className="w-6 h-6 text-white" />
            ) : (
              <VideoOff className="w-6 h-6 text-white" />
            )}
          </button>

          <button
            onClick={leaveRoom}
            className="p-4 rounded-full bg-red-600 hover:bg-red-700 transition"
          >
            <PhoneOff className="w-6 h-6 text-white" />
          </button>
        </div>
      </div>
    </div>
  );
}
