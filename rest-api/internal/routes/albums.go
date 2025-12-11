package routes

import (
	"api/internal/handlers"

	"github.com/gin-gonic/gin"
)

func RegisterAlbumRoutes(r *gin.Engine) {
	r.GET("/albums", handlers.GetAlbums)
	r.GET("/albums/:id", handlers.GetAlbumByID)
	r.POST("/albums", handlers.CreateAlbum)
	r.PUT("/albums/:id", handlers.UpdateAlbum)
	r.DELETE("/albums/:id", handlers.DeleteAlbum)
}
