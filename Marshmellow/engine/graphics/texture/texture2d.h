#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "texture2ddata.h"
#include "textureparams.h"

class Tex2D
{
public:
    Tex2D( Texture2DData* data, TextureParams params );
    Tex2D( const Tex2D &other ) = delete;
    Tex2D& operator=( const Tex2D &other ) = delete;
    Tex2D( Tex2D &&other );
    Tex2D& operator=( Tex2D &&other );
    ~Tex2D();

    void bind();
    void unbind();

    TEXTURE_2D_FORMAT getFormat() const;
    size_t getWidth() const;
    size_t getHeight() const;

private:
    unsigned int m_handle;
    TEXTURE_2D_FORMAT m_format;
    size_t m_width;
    size_t m_height;
};

#endif // TEXTURE2D_H
