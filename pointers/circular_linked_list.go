package main

import "fmt"

type Node struct {
	value		int
	next		*Node
	prev		*Node
}

func Create(value int) *Node {
	return &Node{value: value, next: nil, prev: nil}
}

func Delete(value int, head *Node) {
	curr := head
	for {
		if (*curr).value == value {
			back := (*curr).prev
			front := (*curr).next
			curr = nil
			(*back).next = front
			(*front).prev = back
			break
		} else {
			curr = curr.next
		}
	}
}

func Traverse(head *Node) {
	curr := head
	for {
		fmt.Println(curr.prev.value, "<-", curr.value, "->", curr.next.value)
		curr = (*curr).next
		if curr == head {
			break
		}
	}
}

func main() {
	Node1 := Create(1)
	Node2 := Create(2)
	Node3 := Create(3)
	Node4 := Create(4)

	(*Node1).next = Node2
	(*Node2).next = Node3
	(*Node3).next = Node4
	(*Node4).next = Node1

	(*Node1).prev = Node4
	(*Node2).prev = Node1
	(*Node3).prev = Node2
	(*Node4).prev = Node3

	Traverse(Node1)

	Delete(2, Node1)

	fmt.Println("\n")

	Traverse(Node1)
}
