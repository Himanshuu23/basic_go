package pdfprocessing

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

type ExtractResult struct {
	OutputDir string   `json:"outputDir"`
	TextFile  string   `json:"textFile"`
	Images    []string `json:"images"`
}

func ProcessPDF(pdfPath string) (*ExtractResult, error) {
	base := strings.TrimSuffix(filepath.Base(pdfPath), filepath.Ext(pdfPath))
	outDir := filepath.Join("output", base)

	// create output folder
	if err := os.MkdirAll(outDir, 0755); err != nil {
		return nil, err
	}

	// 1️⃣ Extract text
	textFile := filepath.Join(outDir, "content.txt")
	cmdText := exec.Command("pdftotext", "-layout", pdfPath, textFile)
	if err := cmdText.Run(); err != nil {
		return nil, fmt.Errorf("pdftotext failed: %w", err)
	}

	// 2️⃣ Extract images
	imgPrefix := filepath.Join(outDir, "img")
	cmdImg := exec.Command("pdfimages", "-all", pdfPath, imgPrefix)
	_ = cmdImg.Run()

	// 3️⃣ Collect images
	var images []string
	files, _ := filepath.Glob(filepath.Join(outDir, "img*"))
	for _, f := range files {
		images = append(images, f)
	}

	return &ExtractResult{
		OutputDir: outDir,
		TextFile:  textFile,
		Images:    images,
	}, nil
}
