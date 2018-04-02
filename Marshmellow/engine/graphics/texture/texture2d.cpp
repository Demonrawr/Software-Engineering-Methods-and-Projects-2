#include "texture2d.h"

#define GLEW_STATIC
#include "GL/glew.h"

#include <QImage>
#include <QString>

Tex2D::Tex2D(Texture2DData* data, TextureParams params) :
    m_handle( 0 ),
    m_format( data->format ),
    m_width( data->width ),
    m_height( data->height )
{
    glGenTextures(1, &m_handle);

    if( m_handle != 0 )
    {
       glBindTexture( GL_TEXTURE_2D, m_handle );
       glTexImage2D( GL_TEXTURE_2D, 0, params.colorFormat, m_width, m_height, 0 , params.colorFormat, GL_UNSIGNED_BYTE, data->data );
       glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, params.filterMethod );
       glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, params.filterMethod );
       glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, params.wrapMethod );
       glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, params.wrapMethod );
       glBindTexture( GL_TEXTURE_2D, 0 );
    }
    else
    {
       m_handle = 0;
       fprintf(stderr, "Texture failed to load properly.\n" ); //print to stderr...
    }
}

Tex2D::Tex2D( Tex2D &&other ) :
    m_handle( other.m_handle ),
    m_format( other.m_format ),
    m_width( other.m_width ),
    m_height( other.m_height )
{
    other.m_handle = 0;
    other.m_width = 0;
    other.m_height = 0;
}

Tex2D& Tex2D::operator=( Tex2D &&other )
{
    this->~Tex2D();

    m_handle = other.m_handle;
    m_format = other.m_format;
    m_width = other.m_width;
    m_height = other.m_height;

    other.m_handle = 0;
    other.m_width = 0;
    other.m_height = 0;

    return *this;
}

Tex2D::~Tex2D()
{
    if( m_handle != 0 )
    {
        glDeleteTextures( 1, &m_handle );
    }
}

void Tex2D::bind()
{
    glBindTexture( GL_TEXTURE_2D, m_handle );
}

void Tex2D::unbind()
{
    glBindTexture( GL_TEXTURE_2D, 0 );
}

TEXTURE_2D_FORMAT Tex2D::getFormat() const
{
    return m_format;
}

size_t Tex2D::getWidth() const
{
    return m_width;
}

size_t Tex2D::getHeight() const
{
    return m_height;
}
