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
	json := `{"name": "something", "age": 32}`
	p := Person{"something", 32}
	var result map[string]any
	result1, _ := json.Marshal([]byte(json))
	result2, _ := json.MarshalIndent(p)
	result3, _ := json.Marshal(map[string]int{"one": 1, "two": 2})
	result4 := json.Unmarshal(json, &result)

	fmt.Println(result, result1, result2, result3, result4)
}
