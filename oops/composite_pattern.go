package main

import "fmt"

type Component interface {
	Print()
}

type Folder struct {
	Name		string
	Children	[]Component
}

type File struct {
	Name		string
}

func (f Folder) Print() {
	fmt.Println(f.Name)
	for _, child := range f.Children {
		fmt.Println(child)
	}
}

func Print(c Component) {
	c.Print()
}

func main() {
	file1 := File{"file1"}
	file2 := File{"file2"}
	file3 := File{"file3"}
	
	folder1 := Folder{
		Name:		"Folder 1",
		Children:	[]Component{file1, file2, file3}
	}

	Print(folder1)
}
