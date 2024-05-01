#include "log.h"
#include "file.h"
#include "extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define FORMAT "%Y-%m-%d %H:%M:%S"
#define BYTELEN 50
#define FILENAME "test/test.jpg"
#define FILENAME_OUT "test/out.jpg"

int main() {
    LogConfig *ctx = NULL;
    uint8_t *buf;
    size_t len;

    init_log_ctx(&ctx, FORMAT, BYTELEN);
    if (!ctx) {
        return 1;
    }
    log_out(&ctx, stdout, "test");
    free_log_ctx(&ctx);

    if (readFile(&buf, &len, FILENAME) != 0) {
        return 1;
    }

    if (writeFile(&buf, &len, FILENAME_OUT) != 0) {
        return 1;
    }

    printf("Starting to hexdump\n");
    hexdump_uint8(stdout, buf, len);
    printf("Hexdumped\n");

    free(buf);
}