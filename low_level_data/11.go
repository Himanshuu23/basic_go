package main

import (
	"fmt"
	"bytes"
	"encoding/gob"
)

type Person struct {
	ID	int
	Salary	float64
}

func main() {
	p1 := Person{1, 22.23}

	var buf bytes.Buffer

	encoder := gob.NewEncoder(&buf)

	if err := encoder.Encode(p1); err != nil {
		fmt.Println(err)
	}

	fmt.Println(buf.Bytes())
}
