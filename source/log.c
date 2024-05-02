#include "log.h"

void init_log_ctx(LogConfig **ctx, const char *format, const uint8_t time_str_bytelen) {

    // allocate context
    *ctx = (LogConfig *)malloc(sizeof(LogConfig));
    if (!(*ctx)) {
        perror("Failed to allocate memory");
        goto clean;
    }   

    // set format in config struct
    (*ctx)->format = strdup(format);
    if ((*ctx)->format == NULL) {
        perror("Failed to allocate memory");
        goto clean;
    }

    (*ctx)->time_str_bytelen = time_str_bytelen;

    return;

    clean:
        if (*ctx) {
            free(*ctx);
        }
}

void free_log_ctx(LogConfig **ctx) {
    if (*ctx) {
        free((*ctx)->format);
        free(*ctx);
        *ctx = NULL;
    }
}

void log_out(LogConfig **ctx, FILE *stream, const char *msg) {
    time_t cur_time;
    struct tm *t_info;
    char *time_str = NULL;

    // allocate time str based on macro from header
    time_str = (char *)malloc(((*ctx)->time_str_bytelen + 1) * sizeof(char));
    if (!time_str) {
        perror("Memory allocation failed");
        return;
    }

    // get current time
    time(&cur_time);
    t_info = localtime(&cur_time);

    // format time
    if (strftime(time_str, (*ctx)->time_str_bytelen + 1, (*ctx)->format, t_info) == 0) {
        perror("Error formatting time");
        free(time_str);
        return;
    }

    fprintf(stream, "[%s]: %s\n", time_str, msg);
    free(time_str);
}