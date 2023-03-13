#include "generators.h"
#include "image.h"
#include "imageOP.h"
#include "picTransformer.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum read_status from_bmp(FILE * const in, struct image *img){
    struct bmp_header header = {0};
    if (!read_header(in, &header)) return READ_INVALID_HEADER;
    size_t c = 0;
    *img = generate_pic(header.biHeight, header.biWidth);
    for (size_t i = 0; i < header.biHeight; i++){
        for (size_t j = 0; j < header.biWidth; j++) {
            fread(img->data + c, sizeof(struct pixel), 1, in);
            c++;
        }
        fseek(in, get_padding(header.biWidth), SEEK_CUR);
    }
    return READ_OK;
}


enum write_status to_bmp(FILE * const out, const struct image * const img){
    struct bmp_header header = generate_header(img);
    size_t c = 0;
    fwrite(&header, sizeof(struct bmp_header), 1, out);
    fseek(out, header.bOffBits, SEEK_SET);
    uint8_t trash = 0;
    for (size_t i = 0; i < img->height; i++){
        for (size_t j = 0; j < img->width; j++) {
            fwrite(img->data + c, sizeof(struct pixel), 1, out);
            c++;
        }
        for (int64_t k = 0; k < get_padding(img->width); k++) {
            fwrite(&trash, 1, 1, out);
        }
    }
    return WRITE_OK;
}

struct image transform(const struct image * const orig){
    struct image rot = generate_pic(orig->width, orig->height);
    size_t c = 0;
    for (int64_t i = 0; i < orig->width; i++) {
        for (int64_t j = 0; j < orig->height; j++) {
            size_t ind = i + (orig->width * (orig->height - j - 1));
            rot.data[c] = orig->data[ind];
            c++;
        }
    }
    return rot;
}
