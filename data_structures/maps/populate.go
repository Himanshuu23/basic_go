package main

import "fmt"

func main() {
	capitals := make(map[string]string)

	var key, value string

	fmt.Println("Enter any five countries with their capitals")
	for {
		if len(capitals) > 5 {
			break
		}
		fmt.Scanln(&key, &value)
		capitals[key] = value
	}

	for key, value := range capitals {
		fmt.Println(key, "->",value)
	}
}
