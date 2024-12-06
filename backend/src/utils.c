#include "utils.h"
#include <stdio.h>
#include <time.h>

void log_message(const char *msg) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);
    printf("[%s] %s\n", time_str, msg);
}
