#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGE_TRANSFORMER_IMAGEOP_H
#define IMAGE_TRANSFORMER_IMAGEOP_H
bool read_header(FILE *src, struct bmp_header *header);
int64_t get_padding(uint32_t width);
#endif //IMAGE_TRANSFORMER_IMAGEOP_H
