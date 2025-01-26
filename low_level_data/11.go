package main

import (
	"fmt"
	"bytes"
	"encoding/gob"
)

type Employee struct {
	ID	int
	Salary	float64
}

func main() {
	p1 := Employee{1, 22.23}
	var decoded Employee

	var buf bytes.Buffer

	encoder := gob.NewEncoder(&buf)
	decoder := gob.NewDecoder(&buf)

	if err := encoder.Encode(p1); err != nil {
		fmt.Println(err)
	}
	
	if err := decoder.Decode(&decoded); err != nil {
		fmt.Println(err)
	}

	fmt.Println(buf.Bytes())
	fmt.Println(decoded)
}
