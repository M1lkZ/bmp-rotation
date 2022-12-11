#include "imageOP.h"
#include "image.h"
#include "generators.h"
#include "picTransformer.h"


int main( int argc, char** argv ) {
    if (argc != 3){
        fprintf(stderr, "Invalid arguments. Expected: path input.bmp output.bmp");
        return -1;
    }
    char* file = argv[1];
    char* rotated = argv[2];
    FILE *src = fopen(file,"rb");
    struct bmp_header header = read_header(src);
    struct image orig = generate_pic(header.biHeight, header.biWidth);
    struct image rot = generate_pic(header.biWidth, header.biHeight);
    read_pixels(src, orig, header);
    fclose(src);

    transform(orig, rot);

    FILE *dest = fopen(rotated, "wb");
    write_img(dest, rot, generate_header(rot));
    fclose(dest);
    free(orig.data);
    free(rot.data);
    return 0;
}
