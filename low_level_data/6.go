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
	jsonStr := `{"name": "something", "age": 32}`
	p := Person{"something", 32}
	var result map[string]any
	result1, _ := json.Marshal([]byte(jsonStr))
	result2, _ := json.MarshalIndent(p, "", " ")
	result3, _ := json.Marshal(map[string]int{"one": 1, "two": 2})
	json.Unmarshal([]byte(jsonStr), &result)

	fmt.Println(result, string(result1), string(result2), string(result3))
}
