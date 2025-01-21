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
	jsonData, err := json.Marshal(person)
	jsonData2, err := json.MarshalIndent(person, "", " ")
	erro := json.Unmarshal(Json, &result)
	if err != nil {
		fmt.Println(err, erro)
	}
	fmt.Println(jsonData, jsonData2, result)
}
