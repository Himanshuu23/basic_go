package main

import "fmt"

const (
	FlagA = 1 << iota
	FlagB
	FlagC
	FlagD
)

func setBit(value int, flag int) int {
	return value | flag
}

func clearBit(value int, flag int) int {
	return value &^ flag
}

func toggleBit(value int, flag int) int {
	return value ^ flag
}

func isBitSet(value int, flag int) bool {
	return value&flag != 0
}

func main() {
	var value int

	value = setBit(value, FlagA)
	value = setBit(value, FlagC)

	fmt.Printf("Value after setting Flag A and C is %b\n", value)

	value = clearBit(value, FlagA)

	fmt.Printf("Value after clearing FlagA is %b\n", value)

	value = toggleBit(value, FlagB)

	fmt.Printf("Value after toggling FlagB is %b\n", value)

	fmt.Printf("Is FlagA set? %v\n", isBitSet(value, FlagA))
	
	fmt.Printf("Is FlagB set? %v\n", isBitSet(value, FlagB))
	
	fmt.Printf("Is FlagC set? %v\n", isBitSet(value, FlagC))
}
