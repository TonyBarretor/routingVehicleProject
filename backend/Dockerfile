FROM debian:latest

# Install dependencies
RUN apt-get update && apt-get install -y gcc make libmicrohttpd-dev libcurl4-openssl-dev && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app
COPY . .

RUN make

EXPOSE 8080

CMD ["./server"]
