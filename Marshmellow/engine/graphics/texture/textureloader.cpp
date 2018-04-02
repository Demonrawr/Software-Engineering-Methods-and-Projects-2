#include "textureloader.h"

#include <cassert>
#include <cstdio>

#include <GL/glew.h>

#include <QImage>

#include "texture2d.h"
#include "texture2ddata.h"

TextureLoader::TextureLoader()
{
}

Tex2D TextureLoader::loadTex2D( const std::string &path, TextureParams p ) //add a default param here or just another call
{
    return initTex2D( path, p );
}

Tex2D TextureLoader::initTex2D( const std::string &path , TextureParams p) //add a params thingy here
{
   QImage img;
   img.load(QString::fromStdString(path));
   img = img.mirrored(false, true);
   img = img.convertToFormat( QImage::Format_RGBA8888 );

   Texture2DData data;
   data.data = img.bits();
   data.width = img.width();
   data.height = img.height();

   switch( img.format() )
   {
   case QImage::Format_RGB888:
       data.format = TEXTURE_2D_FORMAT::RGB;
       break;
   case QImage::Format_ARGB32:
   case QImage::Format_RGBA8888:
       data.format = TEXTURE_2D_FORMAT::RGBA;
       break;
   default:
       fprintf(stderr, "Bad image format for: %s\n", path.c_str() );
   }
   return Tex2D( &data, p );
}
