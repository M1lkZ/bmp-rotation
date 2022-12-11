//
// Created by nick on 12/11/22.
//

#ifndef IMAGE_TRANSFORMER_PICTRANSFORMER_H
#define IMAGE_TRANSFORMER_PICTRANSFORMER_H
#include <stdio.h>
#include "image.h"

void read_pixels(FILE *src, struct image img, struct bmp_header header);

void write_img(FILE *dest, struct image img, struct bmp_header header);

void transform(struct image orig, struct image rot);
#endif //IMAGE_TRANSFORMER_PICTRANSFORMER_H
