package main

import (
    "net/http"

    "github.com/gin-gonic/gin"
)

type Person struct {
    Name	string	`json:"name"`
    Age		int	`json:"age"`
    Profession	string	`json:"profession"`
}

var People = []Person{
    {Name: "A", Age: 1, Profession: "Doctor"},
    {Name: "B", Age: 2, Profession: "Teacher"},
    {Name: "C", Age: 3, Profession: "Nurse"},
}

func main() {
    router := gin.Default()
    router.GET("/people", getPerson)
    router.POST("/people", createPerson)
    router.GET("/people/:name", getPersonByName)

    router.Run("localhost:8080")
}

func getPerson(c *gin.Context) {
    c.JSON(http.StatusOK, People)
}

func createPerson(c *gin.Context) {
    var person Person

    if err := c.BindJSON(&person); err != nil {
	return
    }

    People = append(People, person)
}

func getPersonByName(c *gin.Context) {
    name := c.Param("name")

    for _, p := range People {
	if p.Name == name {
	    c.IndentedJSON(http.StatusOK, p)
	    return
	}
    }
    
    c.IndentedJSON(http.StatusNotFound, gin.H{"message": "person not found"})
}
