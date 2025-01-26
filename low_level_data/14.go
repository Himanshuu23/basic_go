package main

import (
	"bytes"
	"encoding/gob"
	"time"
	"fmt"
)

type Timestamp struct {
	Time	time.Time
}

func (T Timestamp) MarshalJSON() string {
	return T.Time
}

func main() {
	t := Timestamp{Time: time.Now()}
	something := t.MarshalJSON()
	fmt.Println(something)
}
