package main

import "fmt"

type Logger struct {
	Data		string
}

var LoggerInstance *Logger

func GetFirstInstance(data string) *Logger {
	if LoggerInstance != nil {
		fmt.Print("already exists")
		return nil
	}

	fmt.Print("about to return the first instance...")
	LoggerInstance = &Logger{Data: data}
	return LoggerInstance
}

func main() {
	logger := GetFirstInstance("this is the firt request")
	fmt.Print("requesting for the first time...")
	fmt.Println(logger)

	logger2 := GetFirstInstance("this is the second request")
	fmt.Println(logger2)
}
