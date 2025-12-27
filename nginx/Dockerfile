FROM golang:1.25 AS builder
WORKDIR /app
COPY . .
ENV CGO_ENABLED=0 GOOS=linux GOARCH=amd64
RUN go build -o app ./app

FROM alpine
WORKDIR /app
EXPOSE 90
COPY --from=builder /app/app .
CMD ["./app"]
