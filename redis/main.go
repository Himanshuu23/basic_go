package main

import (
	"context"
	"encoding/json"
	"fmt"
	
	"github.com/google/uuid"
	"github.com/go-redis/redis/v8"
)

func main() {
	client := redis.NewClient(&redis.Options{
		Addr: 		"localhost:6379",
		Password: 	"",
		DB: 		0,
	})

	ping, err := client.Ping(context.Background()).Result()
	if err != nil {
		fmt.Println(err.Error())
		return
	}

	fmt.Println(ping)
	
	type Person struct {
		ID			string
		Name		string	`json:"name"`
		Age			int		`json:"age"`
		Occupation	string	`json:"occupation"`
	}
	
	himID := uuid.NewString()
	jsonString, err := json.Marshal(Person{
		ID:			himID,
		Name: 		"himanshuuu",
		Age: 		20,
		Occupation: "Staff Software Engineer",
	})

	if err != nil {
		fmt.Printf("failed to marshal: %s", err.Error())
		return
	}

	himKey := fmt.Sprintf("person:%s", himID)

	err = client.Set(context.Background(), himKey, jsonString, 0).Err()

	if err != nil {
		fmt.Printf("Failed to set value in the redis instance: %s", err.Error())
		return
	}

	val, err := client.Get(context.Background(), himKey).Result()
	if err != nil {
		fmt.Printf("Failed to get value from redis: %s", err.Error())
		return
	}

	fmt.Printf("Value retrieved from redis: %s\n", val)
}
