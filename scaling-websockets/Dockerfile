FROM golang:1.25 as builder
WORKDIR /app
COPY . .
ENV CGO_ENABLED=0 GOOS=linux GOARCH=amd64
RUN go build -o /app/server ./app/producer

FROM alpine
WORKDIR /app
EXPOSE 90
COPY --from=builder /app/server .
CMD ["./server"]
