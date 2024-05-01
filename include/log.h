#ifndef LOG_H
#define LOG_H

#include <stdint.h>
#include <stdio.h>

typedef struct {
    char *format;
    uint8_t time_str_bytelen;
} LogConfig;

void init_log_ctx(LogConfig **ctx, const char *format, const uint8_t time_str_bytelen);
void free_log_ctx(LogConfig **ctx);
void log_out(LogConfig **ctx, FILE *stream, const char *msg);

#endif // LOG_H