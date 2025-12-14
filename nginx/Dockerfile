FROM golang:1.22-alpine
WORKDIR .
COPY main.go .
RUN go build -o app
CMD ["./app"]
