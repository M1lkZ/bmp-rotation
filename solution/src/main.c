#include "image.h"
#include "imageOP.h"
#include "picTransformer.h"


int main(int argc, char** argv) {
    if (argc != 3){
        fprintf(stderr, "Invalid arguments. Expected: %s input.bmp output.bmp", argv[0]);
        return -1;
    }
    char* file = argv[1];
    char* rotated = argv[2];

    FILE *src = fopen(file,"rb");
    if (!src){
        fprintf(stderr, "Cannot open file: %s in read mode\n", argv[1]);
        return -1;
    }

    struct image orig;
    enum read_status read_status = from_bmp(src, &orig);
    if(read_status != 0){
        printf("Read error: %d", read_status);
        return read_status;
    }
    fclose(src);

    FILE *dest = fopen(rotated, "wb");
    if(!dest){
        fprintf(stderr, "Cannot open file: %s in write mode\n", argv[2]);
        return -1;
    }
    struct image rot = transform(&orig);
    enum write_status write_status = to_bmp(dest, &rot);
    if(write_status != 0){
        printf("Write error: %d", write_status);
        return -1;
    }
    fclose(dest);
    free(orig.data);
    free(rot.data);
    return 0;
}
