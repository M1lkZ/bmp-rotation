#include "image.h"
#include "imageOP.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void read_pixels(FILE *src, struct image img, struct bmp_header header){
    size_t c = 0;
    for (int i = 0; i < header.biHeight; i++){
        for (int j = 0; j < header.biWidth; j++) {
            fread(img.data + c, sizeof(struct pixel), 1, src);
            c++;
        }
        fseek(src, get_padding(header.biWidth),SEEK_CUR);
    }
}


void write_img(FILE *dest, struct image img, struct bmp_header header){
    size_t c = 0;
    fwrite(&header, sizeof(struct bmp_header), 1, dest);
    fseek(dest, header.bOffBits, SEEK_SET);
    uint8_t trash = 0;
    for (int i = 0; i < img.height; i++){
        for (int j = 0; j < img.width; j++) {
            fwrite(img.data + c, sizeof(struct pixel), 1, dest);
            c++;
        }
        for (int k = 0; k < get_padding(img.width); k++) {
            fwrite(&trash, 1, 1, dest);
        }
    }

}

void transform(struct image orig, struct image rot){
    size_t c = 0;
    for (int i = 0; i < orig.width; i++) {
        for (int j = 0; j < orig.height; j++) {
            size_t ind = i + (orig.width * (orig.height - j - 1));
            rot.data[c] = orig.data[ind];
            c++;
        }
    }
}
