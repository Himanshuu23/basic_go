package main

import (
	"io/ioutil"
	"log"
	"fmt"
)

func main() {
	data, err := ioutil.ReadFile("./test.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(data)

	text := "Writing this inside the file"
	err := ioutil.WriteFile("./test.txt", text, 0644)
	if err != nil {
		log.Fatal(err)
	}
}
