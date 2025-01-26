package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

type Person struct {
	Name string
	Age  int64
}

func main() {
	p := Person{Name: "myname", Age: 69}

	buf := new(bytes.Buffer)

	nameLen := int32(len(p.Name))
	if err := binary.Write(buf, binary.BigEndian, nameLen); err != nil {
		fmt.Println(err)
	}

	if err := binary.Write(buf, binary.BigEndian, []byte(p.Name)); err != nil {
		fmt.Println(err)
	}

	if err := binary.Write(buf, binary.BigEndian, p.Age); err != nil {
		fmt.Println(err)
	}

	fmt.Println("Binary data:", buf.Bytes())

	buffReader := bytes.NewReader(buf.Bytes())
	var q Person

	var nameLenRead int32
	if err := binary.Read(buffReader, binary.BigEndian, &nameLenRead); err != nil {
		fmt.Println(err)
	}

	nameBytes := make([]byte, nameLenRead)
	if err := binary.Read(buffReader, binary.BigEndian, &nameBytes); err != nil {
		fmt.Println(err)
	}

	q.Name = string(nameBytes)

	if err := binary.Read(buffReader, binary.BigEndian, &q.Age); err != nil {
		fmt.Println(err)
	}

	fmt.Println(q)
}
