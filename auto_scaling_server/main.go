package main

import (
    "fmt"
	"github.com/gin-gonic/gin"
)

func handler(c *gin.Context) {
    fmt.Printf("Server Started\n")
	c.JSON(200, gin.H{"message": "Hello World", "status": "success"})
}

func main() {
	r := gin.Default()

	r.GET("/", handler)
	r.Run(":8080")
}
