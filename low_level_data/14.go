package main

import (
	"time"
	"fmt"
)

type Timestamp struct {
	Time	time.Time
}

func (T Timestamp) MarshalJSON() ([]byte, error) {
	date := T.Time.Format("2006-01-02")
	return []byte(`"` + date + `"`), nil
}

func (T *Timestamp) UnmarshalJSON(data []byte) error {
    parsedTime, err := time.Parse("2006-01-02", string(data))
    if err != nil {
        return err
    }
    
    T.Time = parsedTime
    return nil
}

func main() {
	t := Timestamp{Time: time.Now()}
	
	marshal, _ := t.MarshalJSON()
	fmt.Print(marshal)
	
	_ = t.UnmarshalJSON(marshal)
	fmt.Println(t.Time)
}
