#ifndef SHADERVAR_H
#define SHADERVAR_H

#include <cstring>
#include <string>
#include <GL/glew.h>
#include "glm/glm.hpp"

#include "engine/graphics/texture/texture2d.h"

struct ShaderVar
{
      enum TYPE { FLOAT, VEC2, VEC3, VEC4, MAT2, MAT3, MAT4, TEXTURE1D, TEXTURE2D, TEXTURE3D, TEX2D, TEXCUBE };

      union Val
      {
            GLfloat f;
            GLfloat v2[ 2 ];
            GLfloat v3[ 3 ];
            GLfloat v4[ 4 ];
            GLfloat m2[ 4 ];
            GLfloat m3[ 9 ];
            GLfloat m4[ 16 ];
            Tex2D *tex2D;
      };
      // TODO: Create array versions for all of these
      // ShaderVar( GLfloat *f, int c, std::string n ) : count(count), name( n ), type( FLOAT ) { val.f = f }

      ShaderVar( GLfloat    f , std::string n ) : name( n ), type( FLOAT ) { val.f = f; }
      ShaderVar( glm::vec2  v2, std::string n ) : name( n ), type( VEC2 ) { memcpy(val.v2, &v2[0], sizeof(val.v2)); }
      ShaderVar( glm::vec3  v3, std::string n ) : name( n ), type( VEC3 ) { memcpy(val.v3, &v3[0], sizeof(val.v3)); }
      ShaderVar( glm::vec4  v4, std::string n ) : name( n ), type( VEC4 ) { memcpy(val.v4, &v4[0], sizeof(val.v4)); }
      ShaderVar( glm::mat2  m2, std::string n ) : name( n ), type( MAT2 ) { memcpy(val.m2, &m2[0], sizeof(val.m2)); }
      ShaderVar( glm::mat3  m3, std::string n ) : name( n ), type( MAT3 ) { memcpy(val.m3, &m3[0], sizeof(val.m3)); }
      ShaderVar( glm::mat4  m4, std::string n ) : name( n ), type( MAT4 ) { memcpy(val.m4, &m4[0], sizeof(val.m4)); }

      ShaderVar( Tex2D     *t2, std::string n ) : name( n ), type( TEX2D )     { val.tex2D = t2; }

      // Possibly overload Val = operator instead
      void setValue( GLfloat f ) { val.f = f; }
      void setValue( glm::vec2 v2 ) { memcpy( &val.v2, &v2, sizeof(GLfloat)*2 ); }
      void setValue( glm::vec3 v3 ) { memcpy( &val.v3, &v3, sizeof(GLfloat)*3 ); }
      void setValue( glm::vec4 v4 ) { memcpy( &val.v4, &v4, sizeof(GLfloat)*4 ); }
      void setValue( glm::mat2 m2 ) { memcpy( &val.m2, &m2, sizeof(GLfloat)*2*2 ); }
      void setValue( glm::mat3 m3 ) { memcpy( &val.m3, &m3, sizeof(GLfloat)*3*3 ); }
      void setValue( glm::mat4 m4 ) { memcpy( &val.v4, &m4, sizeof(GLfloat)*4*4 ); }
      void setValue( Tex2D    *t2 ) { val.tex2D = t2; }

      // int count;
      std::string name;
      TYPE type;
      Val val;

};

#endif // SHADERVAR_H
