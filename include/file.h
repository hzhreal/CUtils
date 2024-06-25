#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

int readFile(uint8_t **buf, size_t *len, const char *filename);
int writeFile(const uint8_t *buf, const size_t len, const char *filename);

#endif // FILE_H