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
}
