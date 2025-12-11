package handlers

import (
	"net/http"
	"api/internal/models"

	"github.com/gin-gonic/gin"
)

func GetAlbums(c *gin.Context) {
	c.IndentedJSON(http.StatusOK, models.Albums)
}

func GetAlbumByID(c *gin.Context) {
	id := c.Param("id")

	for _, a := range models.Albums {
		if a.ID == id {
			c.IndentedJSON(http.StatusOK, a)
			return
		}
	}

	c.JSON(http.StatusNotFound, gin.H{"message": "album not found"})
}

func CreateAlbum(c *gin.Context) {
	var newAlbum models.Album

	if err := c.BindJSON(&newAlbum); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	models.Albums = append(models.Albums, newAlbum)
	c.JSON(http.StatusCreated, newAlbum)
}

func DeleteAlbum(c *gin.Context) {
	id := c.Param("id")

	for i, a := range models.Albums {
		if a.ID == id {
			models.Albums = append(models.Albums[:i], models.Albums[i+1:]...)
			c.JSON(http.StatusOK, gin.H{"message": "album deleted"})
			return
		}
	}

	c.JSON(http.StatusNotFound, gin.H{"error": "album not found"})
}

func UpdateAlbum(c *gin.Context) {
	id := c.Param("id")
	var updated models.Album

	if err := c.BindJSON(&updated); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	for i, a := range models.Albums {
		if a.ID == id {
			models.Albums[i] = updated
			c.JSON(http.StatusOK, updated)
			return
		}
	}

	c.JSON(http.StatusNotFound, gin.H{"error": "album not found"})
}
