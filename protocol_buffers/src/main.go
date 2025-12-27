package main

import (
	"fmt"
	"log"

	"google.golang.org/protobuf/proto"
)

func main() {
	himanshu := &Person{
		Name: "Himanshu",
		Age: 20,
		SocialFollowers: &SocialFollowers{
			Github: 1000,
			Twitter: 1000,
		},
	}

	data, err := proto.Marshal(himanshu)
	if err != nil {
		log.Fatal("Marshalling error", err.Error())
	}

	fmt.Println(data)

	newHimanshu := &Person{}
	err = proto.Unmarshal(data, newHimanshu)
	if err != nil {
		log.Fatal("Unmarshalling error", err.Error())
	}
	
	fmt.Println(newHimanshu.GetName())
	fmt.Println(newHimanshu.GetAge())
	fmt.Println(newHimanshu.SocialFollowers.GetGithub())
	fmt.Println(newHimanshu.SocialFollowers.GetTwitter())
}
