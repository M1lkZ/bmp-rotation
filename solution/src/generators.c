
#include "image.h"
#include "imageOP.h"
#include <stdint.h>
#include <malloc.h>

struct image generate_pic(uint32_t height, uint32_t width){
    struct image img;
    struct pixel* data = malloc((width*height) * sizeof(struct pixel));
    img.width = width;
    img.height = height;
    img.data = data;
    return img;
}

struct bmp_header generate_header(struct image img){
    return (struct bmp_header) {
            .bfType = 0x4d42,
            .bfileSize = img.width * img.height * sizeof(struct pixel) + get_padding(img.width) * img.height + sizeof(struct bmp_header),
            .bfReserved = 0,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,
            .biWidth = img.width,
            .biHeight = img.height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = (img.width + get_padding(img.width)) * img.height,
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0,
    };

}
