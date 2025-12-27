package main

import (
	"log"
	"net"

	"google.golang.org/grpc"
	"grpc/chat"
)

// grpc allows to expose functionalities to other applications - used in distributed systems
// grpc uses http 2.0 while rest uses http 1.1, grpc uses protobufs - so data is smaller - so grpc more faster
// grpc also utilizes http2.0 functionality - server, client and bi-directional streaming
// but complex to test - can't use tools like postman
// protoc -I . --go_out=. --go-grpc_out=. chat.proto

func main() {
	lis, err := net.Listen("tcp", ":9000")
	if err != nil {
		log.Fatalf("failed to listen on port 9000: %v", err.Error())
	}

	s := chat.Server{}

	grpcServer := grpc.NewServer()

	chat.RegisterChatServiceServer(grpcServer, &s)

	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("Failed to serve gRPC server over port 9000: %v", err.Error())
	}
}
