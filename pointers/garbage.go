package main

import (
	"fmt"
)
func main() {
	a := 4
	ptr := &a
	fmt.Println(ptr, *ptr, a)
	ptr = nil
	fmt.Println(ptr, ptr, a)
}
