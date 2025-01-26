package main

import (
	"encoding/binary"
	"fmt"
)

func main() {
	var a int32 = 2

	big := binary.LittleEndian.Uint32(a)
	small := binary.BigEndian.Uint32(a)

	fmt.Print(big, small)
