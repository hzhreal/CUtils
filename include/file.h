#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include <stddef.h>

int readFile(uint8_t **buf, size_t *len, const char *filename);
int writeFile(uint8_t **buf, size_t *len, const char *filename);

#endif // FILE_H