package main

import (
	"context"
	"fmt"
	"time"
)

// used to time a certain request - how much time it takes to process, if takes moe than that - then timed out
// helps in computation power of the server and also if server can handle suppose 100 req/sec and some reqs hang and stay in the server
// and 100 new request come then might overload and crash the server so to handle those too.
// Transport Layer (creates the context) -> Business Layer -> Data Layer

func enrichContext(ctx context.Context) context.Context {
	return context.WithValue(ctx, "request-id", "12345")
}

func doSomethingCool(ctx context.Context) {
	rID := ctx.Value("request-id")
	fmt.Println(rID)
	for {
		select {
			case <-ctx.Done():
				fmt.Println("timed out")
				return
			default:
				fmt.Println("doing something cool")
		}
		time.Sleep(500 * time.Millisecond)
	}
}

func main() {
	ctx, cancel := context.WithTimeout(context.Background(), 2*time.Second)
	defer cancel()
	fmt.Println(ctx.Err())
	ctx = enrichContext(ctx)
	go doSomethingCool(ctx)
	select {
		case <-ctx.Done():
			fmt.Println("oh no, I exceeded the deadline")
			fmt.Println(ctx.Err())
	}

	time.Sleep(2 * time.Second)
}
