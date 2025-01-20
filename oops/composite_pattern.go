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
		child.Print()
	}
}

func (f File) Print() {
	fmt.Println(f.Name)
}

func Print(c Component) {
	c.Print()
}

func main() {
	file1 := File{"file1"}
	file2 := File{"file2"}
	file3 := File{"file3"}

	file4 := File{"file4"}
	file5 := File{"file5"}
	
	folder1 := Folder{
		Name:		"Folder 1",
		Children:	[]Component{file1, file2, file3},
	}

	folder2 := Folder{
		Name: 		"Parent Folder",
		Children:	[]Component{folder1, file4, file5},
	}
	
	Print(folder2)
}
