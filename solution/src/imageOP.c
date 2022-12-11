#include <stdio.h>
#include "image.h"

struct bmp_header read_header(FILE *src){
    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, src);
    fseek(src, header.bOffBits, SEEK_SET);
    return header;
}

int64_t get_padding(uint32_t width){
    return (width % 4 == 0) ? 0 : 4 - (int64_t)((width * sizeof(struct pixel)) % 4);
}
