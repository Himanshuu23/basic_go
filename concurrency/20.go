package main

import (
	"fmt"
	"io/ioutil"
	"sync"
)

func readFile(filename string, ch chan<- string, wg *sync.WaitGroup) {
	defer wg.Done()
	content, err := ioutil.ReadFile(filename)
	if err != nil {
		ch <- fmt.Sprintf("Error reading %s: %v", filename, err)
		return
	}
	ch <- fmt.Sprintf("Content of %s:\n%s", filename, content)
}

func main() {
	files := []string{"file1.txt", "file2.txt", "file3.txt"}
	ch := make(chan string)
	var wg sync.WaitGroup

	for _, file := range files {
		wg.Add(1)
		go readFile(file, ch, &wg)
	}

	go func() {
		wg.Wait()
		close(ch)
	}()

	for content := range ch {
		fmt.Println(content)
	}
}
