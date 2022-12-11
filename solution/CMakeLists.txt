file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources} include/image.h src/imageOP.c src/generators.c include/imageOP.h src/picTransformer.c include/picTransformer.h include/generators.h)
target_include_directories(image-transformer PRIVATE src include)
