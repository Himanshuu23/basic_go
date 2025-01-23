package main

import (
	"fmt"
)

func setBit(num, pos int) int {
	return num | 1 << pos
}

func clearBit(num, pos int) int {
	return num & 1 << pos
}

func toggleBit(num, pos int) int {
	return num &^ 1 << pos
}

func main() {
	// fix the things a bit there r bugs regarding the logical bitwise ops
}
