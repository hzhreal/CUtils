#ifndef EXTRA_H
#define EXTRA_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void hexdump_uint8(FILE *stream, const uint8_t *data, size_t len);

#endif // EXTRA_H