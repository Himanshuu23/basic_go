package main

import (
	"fmt"
	"encoding/json"
)

type Person struct {
	Name		string		`json:"name"`
	Age		int		`json:"age"`
}

func main() {
	person := Person{"something", 21}
	var result Person

	Json := []byte(`{"name":"name", "age":29}`)
	jsonData, _ := json.Marshal(person)
	jsonData2, _ := json.MarshalIndent(person, "", " ")
	err := json.Unmarshal(Json, &result)
	if err != nil {
		fmt.Print(err)
	}
	fmt.Println(string(jsonData), string(jsonData2), result)
}
