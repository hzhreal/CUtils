#ifndef EXTRA_H
#define EXTRA_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

void hexdump_uint8(FILE *stream, const uint8_t *data, const size_t len);

#endif // EXTRA_H