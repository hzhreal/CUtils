#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include "file.h"

// returns 0 on success, 1 on failure
int readFile(uint8_t **buf, size_t *len, const char *filename) {
    FILE *fd;
    size_t bytesRead;

    // open file
    fd = fopen(filename, "rb");
    if (!fd) {
        perror("Failed to open file");
        goto clean;
    }

    fseek(fd, 0, SEEK_END);

    // get filesize
    *len = ftell(fd);
    if (*len == 0) {
        perror("File was empty");
        goto clean;
    }

    fseek(fd, 0, SEEK_SET);

    // allocate buffer
    *buf = (uint8_t *)malloc(*len);
    if (!*buf) {
        perror("Failed to allocate buffer");
        goto clean;
    }

    // read file
    bytesRead = fread(*buf, 1, *len, fd);
    if (bytesRead != *len) {
        perror("Wrote insufficent bytes to file");
        goto clean; 
    }

    // cleanup
    fclose(fd);
    return 0;

    clean:
        if (fd) {
            fclose(fd);
        }
        if (*buf) {
            free(*buf);
        }
        return 1;
}

// returns 0 on success, 1 on failure
int writeFile(uint8_t **buf, size_t *len, const char *filename) {
    FILE *fd;
    size_t bytesWritten;

    // open file
    fd = fopen(filename, "wb");
    if (!fd) {
        perror("Failed to open file");
        goto clean;
    }

    // write to file
    bytesWritten = fwrite(*buf, 1, *len, fd);
    if (bytesWritten != *len) {
        perror("Failed to write sufficent bytes.");
        goto clean;
    }

    // cleanup
    fclose(fd);
    return 0;

    clean:
        if (fd) {
            fclose(fd);
        }
        return 1;
}