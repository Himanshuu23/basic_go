package main

import (
	"fmt"
	"log"

	"example.com/greetings"
)

func main() {
	log.SetPrefix("greetings: ")
	log.SetFlags(0)

	names := []string{ "firstName", "secondName", "thirdName", "fourthName" }

	messages, err := greetings.Hellos(names)
	
	if err != nil {
		log.Fatal(err)
	}
	
	for _, message := range messages {
		fmt.Println(message)
	}
}
