#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include "http_server.h"
#include "route_api.h"
#include "utils.h"

#define RESPONSE_SIZE 8192

static int handle_request(void *cls,
                          struct MHD_Connection *connection,
                          const char *url,
                          const char *method,
                          const char *version,
                          const char *upload_data,
                          size_t *upload_data_size,
                          void **con_cls) {
    (void)cls; (void)version; (void)upload_data; (void)upload_data_size; (void)con_cls;

    char response[RESPONSE_SIZE];
    memset(response, 0, RESPONSE_SIZE);

    if (strcmp(url, "/route") == 0 && strcmp(method, "GET") == 0) {
        get_route(response, sizeof(response));
    } else {
        snprintf(response, RESPONSE_SIZE, "{\"error\": \"Invalid endpoint\"}");
    }

    struct MHD_Response *mhd_response = MHD_create_response_from_buffer(strlen(response),
                                                                       (void*)response,
                                                                       MHD_RESPMEM_MUST_COPY);
    int status_code = (strstr(response, "error") != NULL) ? 404 : 200;
    int ret = MHD_queue_response(connection, status_code, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret;
}

void start_server(int port) {
    struct MHD_Daemon *daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, port, NULL, NULL,
                                                 &handle_request, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        fprintf(stderr, "Failed to start server\n");
        return;
    }
    log_message("Server running...");
    // Press Ctrl+C to stop in terminal
    getchar();
    MHD_stop_daemon(daemon);
}
