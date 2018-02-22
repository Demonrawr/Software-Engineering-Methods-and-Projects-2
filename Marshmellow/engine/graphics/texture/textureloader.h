#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <map>
#include <string>
#include <GL/glew.h>

#include "engine/graphics/texture/texture2d.h"
#include "engine/graphics/texture/textureparams.h"


class TextureLoader
{
   public:
      TextureLoader();

      Tex2D loadTex2D( const std::string &path );
      Tex2D loadTex2D( const std::string &path, TextureParams p );

   private:

      Tex2D initTex2D( const std::string &path, TextureParams p );
};

#endif // TEXTURELOADER_H
