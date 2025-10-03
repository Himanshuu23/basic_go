package main

import (
    "fmt"
    "io"
    "net/http"

    "github.com/gin-gonic/gin"
)

const URL1 = "https://jsonplaceholder.typicode.com/posts"
const URL2 = "https://jsonplaceholder.typicode.com/users"

func main() {
    router := gin.Default()
    router.GET("/", getData)

    router.Run("localhost:3000")
}

func fetchUrl(URL string) *http.Response {
    res, err := http.Get(URL)
    
    if err != nil {
        fmt.Printf(err.Error())
    }

    return res
}

func getData(c* gin.Context) {
    resp1 := fetchUrl(URL1)
    resp2 := fetchUrl(URL2)

    defer resp1.Body.Close()
    defer resp2.Body.Close()

    res1, err1 := io.ReadAll(resp1.Body)
    res2, err2 := io.ReadAll(resp2.Body)
    
    if err1 != nil || err2 != nil {
        fmt.Println("Error reading resp1onse's body", err1.Error())
    }
   
    fmt.Printf(string(res1))
    fmt.Printf(string(res2))
}
