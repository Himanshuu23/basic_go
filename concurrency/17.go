package main 

import (
    "fmt"
    "sync"
    "time"
)

const numPhilosophers = 5

type Philosopher struct {
    id                      int
    leftFork, rightFork     *sync.Mutex
}

func (p Philosopher) dine(wg *sync.WaitGroup) {
    defer wg.Done()
    
    for i := 0; i < 3; i++ {
        fmt.Printf("Philosopher %d is thinking.\n", p.id)
        time.Sleep(time.Second)
        
        p.leftFork.Lock()
        fmt.Printf("Philosopher %d picked up left fork.\n", p.id)
		p.rightFork.Lock()
		fmt.Printf("Philosopher %d picked up right fork.\n", p.id)

		fmt.Printf("Philosopher %d is eating.\n", p.id)
		time.Sleep(time.Second)

		p.rightFork.Unlock()
		fmt.Printf("Philosopher %d put down right fork.\n", p.id)
		p.leftFork.Unlock()
		fmt.Printf("Philosopher %d put down left fork.\n", p.id)
    }
}

func main() {
    var wg sync.WaitGroup
    
    forks := make([]sync.Mutex, numPhilosophers)
    
    philosophers := make([]Philosopher, numPhilosophers)
    
	for i := 0; i < numPhilosophers; i++ {
		philosophers[i] = Philosopher{
			id:         i + 1,
			leftFork:   &forks[i],
			rightFork:  &forks[(i+1)%numPhilosophers],
		}
	}
	
	for i := 0; i < numPhilosophers; i++ {
		wg.Add(1)
		go philosophers[i].dine(&wg)
	}

	wg.Wait()
}
