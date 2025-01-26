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

	buffReader := bytes.NewReader(buf.Bytes())
	var q Person

	var nameLen int
	if err := binary.Read(buffReader, binary.BigEndian, &nameLen); err != nil {
		fmt.Println(err)
	}

	nameBytes := make([]byte, nameLen)
	if err := binary.Read(buffReader, binary.BigEndian, &nameBytes); err != nil {
		fmt.Println(err)
	}

	q.Name = string(nameBytes)

	if err := binary.Read(buffReader, binary.BigEndian, &q.Age); err != nil {
		fmt.Println(err)
	}

	fmt.Println(q)
}
