#include "image.h"
#include <stdbool.h>
#include <stdio.h>


bool read_header(FILE * const src, struct bmp_header * const header){
    if (fread(header, sizeof(struct bmp_header), 1, src)){
        fseek(src, header->bOffBits, SEEK_SET);
        return true;
    }
    return false;
}



int64_t get_padding(const uint32_t width){
    return (width % 4 == 0) ? 0 : 4 - (int64_t)((width * sizeof(struct pixel)) % 4);
}
