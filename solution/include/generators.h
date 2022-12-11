//
// Created by nick on 12/11/22.
//

#ifndef IMAGE_TRANSFORMER_GENERATORS_H
#define IMAGE_TRANSFORMER_GENERATORS_H
#include <stdint.h>
struct image generate_pic(uint32_t height, uint32_t width);

struct bmp_header generate_header(struct image img);
#endif //IMAGE_TRANSFORMER_GENERATORS_H
