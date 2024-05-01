#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "extra.h"

void hexdump_uint8(FILE *stream, const uint8_t *data, const size_t len) {
    for (size_t i = 0; i < len; i++) {
        fprintf(stream, "%02x", data[i]);
        if ((i + 1) % 16 == 0 || i == len - 1) {
            fprintf(stream, "\n");
        }
    }
}