package main

import (
    "fmt"
    "io/ioutil"
    "net/http"

    "github.com/gin-gonic/gin"
)

const URL = "https://jsonplaceholder.typicode.com/posts"

func main() {
    router := gin.Default()
    router.GET("/", getPosts)

    router.Run("localhost:3000")
}

func getPosts(c *gin.Context) {
    resp, err := http.Get(URL)

    if err != nil {
        fmt.Printf(err.Error())
    }

    defer resp.Body.Close()

    res, err := ioutil.ReadAll(resp.Body)
    if err != nil {
        fmt.Println("Error reading response's body", err.Error())
    }

    fmt.Println("This is the response: ", string(res))
}
