package main

import (
    "fmt"
    "context"
    "time"
)

func runGoroutine(ctx context.Context) {
    for {
        select {
            case <-ctx.Done():
            fmt.Println("Goroutine stopped: ", ctx.Err())
            return
            
            default:
                fmt.Println("Goroutine is running...")
                time.Sleep(time.Second)
        }
    }
}

func main() {
    ctx, cancel := context.WithTimeout(context.Background(), 5 * time.Second)
    defer cancel()
    
    go runGoroutine(ctx)
    
    time.Sleep(6 * time.Second)
}
