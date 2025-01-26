package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

type Person struct {
	Name		string
	Age 		int64
}

func main() {
	p := Person{Name: "myname", Age: 69}

	buf := new(bytes.Buffer)

	if err := buf.Write([]byte(p.Name)); err != nil {
		fmt.Println(err)
	}
	
	if err := binary.Write(buf, binary.BigEndian, p.Age); err != nil {
		fmt.Println(err)
	}

	fmt.Println("Binary data: ", buf.Bytes())

	buf := bytes.NewReader(buf.Bytes())
	var q Person

	if err := buf.Read(&q.Name); err != nil {
		fmt.Println(err)
	}

	if err := binary.Read(buf, binary.BigEndian, &q.Age); err != nil {
		fmt.Println(err)
	}

	fmt.Println(q)
}
