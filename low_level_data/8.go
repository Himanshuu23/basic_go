package main

import (
	"fmt"
	"encoding/hex"
)

func main() {
	String := "this is a string"

	bytes := []byte(String)
	hexStr := hex.EncodeToString(bytes)

	str, _ := hex.DecodeString(hexStr)
	fmt.Print(hexStr, string(str))
	
}
