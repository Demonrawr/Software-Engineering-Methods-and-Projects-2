#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

#include "engine/graphics/shaders/shadervar.h"

class Shader
{
   public:

      Shader( const std::string &vertexSource, const std::string &fragmentSource );
      Shader( const std::string &vertexSource, const std::string &geometrySource, const std::string &fragmentSource );
      ~Shader();

      void applyUniform( ShaderVar );
      GLuint attrib( std::string );
      void bind();
      void unbind();

      enum ATTRIB {ATTRIB_POSITION = 0,
                   ATTRIB_NORMAL = 1,
                   ATTRIB_TEXCOORD0 = 2,
                   ATTRIB_TEXCOORD1 = 3,
                   ATTRIB_TEXCOORD2 = 4,
                   ATTRIB_TEXCOORD3 = 5};

   protected:
      GLuint m_programHandle;

   private:

      void bindTex2D( Tex2D* tex, GLuint location );

      void checkLinkErrors();
      void printCompileError( GLuint handle );
      void createFragmentShader( const std::string &fragmentSource );
      void createGeometryShader( const std::string &geometrySource );
      void createVertexShader( const std::string &vertexSource );
      void createShader( GLuint, std::string );
};

#endif // SHADER_H
