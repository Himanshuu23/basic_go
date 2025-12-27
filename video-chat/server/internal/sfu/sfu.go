package sfu

import (
    "encoding/json"
    "log"
    "sync"

    "github.com/pion/webrtc/v3"
)

type SFU struct {
    peers map[string]*Peer
    mu    sync.RWMutex
}

type Peer struct {
    ID         string
    PC         *webrtc.PeerConnection
    RemoteTracks []*webrtc.TrackRemote
}

func NewSFU() *SFU {
    return &SFU{
        peers: make(map[string]*Peer),
    }
}

func (s *SFU) CreatePeer(id string) (*Peer, error) {
    config := webrtc.Configuration{
        ICEServers: []webrtc.ICEServer{
            {
                URLs: []string{"stun:stun.l.google.com:19302"},
            },
        },
    }

    pc, err := webrtc.NewPeerConnection(config)
    if err != nil {
        return nil, err
    }

    peer := &Peer{
        ID:         id,
        PC:         pc,
        RemoteTracks: make([]*webrtc.TrackRemote, 0),
    }

    pc.OnTrack(func(track *webrtc.TrackRemote, receiver *webrtc.RTPReceiver) {
        log.Printf("Got track: %s from peer %s", track.Kind(), id)
        peer.RemoteTracks = append(peer.RemoteTracks, track)

        s.mu.RLock()
        for peerID, p := range s.peers {
            if peerID != id {
                s.forwardTrack(track, p)
            }
        }
        s.mu.RUnlock()
    })

    s.mu.Lock()
    s.peers[id] = peer
    s.mu.Unlock()

    return peer, nil
}

func (s *SFU) forwardTrack(track *webrtc.TrackRemote, targetPeer *Peer) {
    localTrack, err := webrtc.NewTrackLocalStaticRTP(track.Codec().RTPCodecCapability, track.ID(), track.StreamID())
    if err != nil {
        log.Printf("Failed to create local track: %v", err)
        return
    }

    rtpSender, err := targetPeer.PC.AddTrack(localTrack)
    if err != nil {
        log.Printf("Failed to add track: %v", err)
        return
    }

    go func() {
        rtcpBuf := make([]byte, 1500)
        for {
            if _, _, rtcpErr := rtpSender.Read(rtcpBuf); rtcpErr != nil {
                return
            }
        }
    }()

    go func() {
        buf := make([]byte, 1500)
        for {
            n, _, err := track.Read(buf)
            if err != nil {
                return
            }
            if _, err = localTrack.Write(buf[:n]); err != nil {
                return
            }
        }
    }()
}

func (s *SFU) HandleOffer(peerID string, offerJSON string) (string, error) {
    peer, err := s.CreatePeer(peerID)
    if err != nil {
        return "", err
    }

    var offer webrtc.SessionDescription
    if err := json.Unmarshal([]byte(offerJSON), &offer); err != nil {
        return "", err
    }

    if err := peer.PC.SetRemoteDescription(offer); err != nil {
        return "", err
    }

    answer, err := peer.PC.CreateAnswer(nil)
    if err != nil {
        return "", err
    }

    if err := peer.PC.SetLocalDescription(answer); err != nil {
        return "", err
    }

    answerJSON, err := json.Marshal(answer)
    if err != nil {
        return "", err
    }

    return string(answerJSON), nil
}

func (s *SFU) RemovePeer(id string) {
    s.mu.Lock()
    defer s.mu.Unlock()

    if peer, exists := s.peers[id]; exists {
        peer.PC.Close()
        delete(s.peers, id)
    }
}
