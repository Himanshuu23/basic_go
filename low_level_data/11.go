package main

import (
	"fmt"
	"bytes"
	"encoding/binary"
)

type Employee struct {
	ID	int32
	Salary	float64
}

func serialize(emp Employee) ([]byte, error) {
	buf := new(bytes.Buffer)

	if err := binary.Write(buf, binary.BigEndian, emp.ID); err != nil {
		return buf.Bytes(), err
	}

	if err := binary.Write(buf, binary.BigEndian, emp.Salary); err != nil {
		return buf.Bytes(), err
	}
	
	return buf.Bytes(), nil
}

func deserialize(data []byte) (Employee, error) {
	buf := bytes.NewReader(data)
	var emp Employee

	if err := binary.Read(buf, binary.BigEndian, &emp.ID); err != nil {
		return emp, err
	}

	if err := binary.Read(buf, binary.BigEndian, &emp.Salary); err != nil {
		return emp, err
	}
	
	return emp, nil
}

func main() {
	emp := Employee{ID: 1, Salary: 22.23}
	
	serializedData, err := serialize(emp)

	if err != nil {
		fmt.Println("Serialization error: ", err)
	}

	fmt.Println("Serialized Data: ", serializedData)

	deserializedData, err := deserialize(serializedData)

	if err != nil {
		fmt.Println("Deserialization error: ", err)
	}

	fmt.Println("Deserialized Data: ", deserializedData)
}
