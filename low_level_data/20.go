package main

import (
	"encoding/binary"
	"os"
	"fmt"
)

func main() {
	file, _ := os.Create("data.bin")
	defer file.Close()

	binary.Write(file, binary.LittleEndian, int32(4))
	binary.Write(file, binary.LittleEndian, float32(3.14))
	file.Close()

	file, _ := os.Open("data.bin")
	defer file.Close()

	var intValue int32
	var floatValue float32

	binary.Read(file, binary.LittleEndian, &intValue)
	binary.Read(file, binary.LittleEndian, &floatValue)

	fmt.Println("Integer: %d\nFloat: %f\n", intValue, floatValue)
}
