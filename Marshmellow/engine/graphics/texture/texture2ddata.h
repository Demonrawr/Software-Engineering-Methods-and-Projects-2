#ifndef TEXTURE2DDATA
#define TEXTURE2DDATA

#include <stddef.h>

enum class TEXTURE_2D_FORMAT {
    RGB,
    RGBA
};

struct Texture2DData
{
    unsigned char *data;
    size_t width;
    size_t height;
    TEXTURE_2D_FORMAT format;
};


#endif // TEXTURE2DDATA

