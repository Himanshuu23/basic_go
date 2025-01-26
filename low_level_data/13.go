package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

func main() {
	num := int32(4)

	bigEndian := new(bytes.Buffer)
	binary.Write(bigEndian, binary.BigEndian, num)
	fmt.Printf("Big Endian: %v\n", bigEndian.Bytes())

	littleEndian := new(bytes.Buffer)
	binary.Write(littleEndian, binary.LittleEndian, num)
	fmt.Printf("Little Endian: %v\n", littleEndian.Bytes())

	var x, y int32

	err1 := binary.Read(bytes.NewReader(bigEndian.Bytes()), binary.BigEndian, &x)
	if err1 != nil {
		fmt.Print(err1)
	}
	fmt.Println("Integer for the Big Endian: ", x, "\n")
	
	err2 := binary.Read(bytes.NewReader(littleEndian.Bytes()), binary.LittleEndian, &y)
	if err1 != nil {
		fmt.Print(err2)
	}
	fmt.Println("Integer for the Little Endian: ", y, "\n")
}
