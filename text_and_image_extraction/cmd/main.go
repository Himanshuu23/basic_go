package main

import (
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
	"ocr/pdf-processing"
)

func main() {
	r := gin.Default()

	// ensure temp folder exists
	_ = os.MkdirAll("tmp", 0755)

	r.POST("/extract", func(c *gin.Context) {
		file, err := c.FormFile("file")
		if err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": "file not found"})
			return
		}

		dst := "tmp/" + file.Filename
		if err := c.SaveUploadedFile(file, dst); err != nil {
			c.JSON(500, gin.H{"error": err.Error()})
			return
		}

		result, err := pdfprocessing.ProcessPDF(dst)
		if err != nil {
			c.JSON(500, gin.H{"error": err.Error()})
			return
		}

		c.JSON(200, result)
	})

	r.Run(":8080")
}
