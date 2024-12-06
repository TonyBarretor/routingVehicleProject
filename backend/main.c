#include "http_server.h"

int main() {
    // Start the HTTP server
    printf("Starting the server...\n");
    start_server(8080); // Listening on port 8080
    return 0;
}
