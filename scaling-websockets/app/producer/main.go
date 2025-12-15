package main

import (
	"encoding/json"
	"log"
	"net/http"

	"github.com/IBM/sarama"
)

type Payment struct {
	SenderName		string	`json:"sender_name"`
	ReceiverType	string	`json:"receiver_name"`
	Amount			float32	`json:"amount"`	
}

func main() {
	http.HandleFunc("/pay", makePayment)
	log.Fatal(http.ListenAndServe(":3000", nil))
}

func ConnectProducer(brokers []string) (sarama.SyncProducer, error) {
	config := sarama.NewConfig()
	config.Producer.Return.Successes = true
	config.Producer.RequiredAcks = sarama.WaitForAll
	config.Producer.Retry.Max = 5

	return sarama.NewSyncProducer(brokers, config)
}

func PushOrderToQueue(topic string, message []byte) error {
	brokers := []string{"localhost:9092"}
	
	producer, err := ConnectProducer(brokers)
	if (err != nil) {
		return err 
	}

	defer producer.Close()

	msg := &sarama.ProducerMessage{
		Topic: topic,
		Value: sarama.StringEncoder(message),
	}

	partition, offset, err := producer.SendMessage(msg)
	if err != nil {
		return err
	}

	log.Printf("Payment Order is stored in topic(%s)/partition(%d)/offset(%d)\n",
		topic,
		partition,
		offset,)
	
	return nil
}

func makePayment(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Invalid request method", http.StatusMethodNotAllowed)
		return
	}

	paymentOrder := new(Payment)
	if err := json.NewDecoder(r.Body).Decode(paymentOrder); err != nil {
		log.Println(err)
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}
	
	paymentOrderInBytes, err := json.Marshal(paymentOrder)
	if err != nil {
		log.Println(err)
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	err = PushOrderToQueue("payment_orders", paymentOrderInBytes)
	if err != nil {
		log.Println(err)
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	response := map[string]interface{}{
		"success":  true,
		"msg": 		"Payment Order for " + paymentOrder.SenderName + " placed successfully!",
	}

	w.Header().Set("Content-Type", "application/json")
	if err := json.NewEncoder(w).Encode(response); err != nil {
		log.Println(err)
		http.Error(w, "Error placing order", http.StatusInternalServerError)
		return
	}
}
