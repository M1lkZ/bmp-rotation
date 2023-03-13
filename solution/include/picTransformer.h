//
// Created by nick on 12/11/22.
//

#ifndef IMAGE_TRANSFORMER_PICTRANSFORMER_H
#define IMAGE_TRANSFORMER_PICTRANSFORMER_H
#include "image.h"
#include <stdio.h>


struct image transform(const struct image *orig);

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
    /* коды других ошибок  */
};

enum read_status from_bmp( FILE* in, struct image* img );

/*  serializer   */
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
    /* коды других ошибок  */
};

enum write_status to_bmp( FILE* out, struct image const* img );

#endif //IMAGE_TRANSFORMER_PICTRANSFORMER_H
