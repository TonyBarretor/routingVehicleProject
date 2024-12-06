CC = gcc
CFLAGS = -Wall -lcurl -lmicrohttpd
TARGET = server

all: $(TARGET)

$(TARGET): main.c src/http_server.c src/route_api.c
	$(CC) main.c src/http_server.c src/route_api.c -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)
