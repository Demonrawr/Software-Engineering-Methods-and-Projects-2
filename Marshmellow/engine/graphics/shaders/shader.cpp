#include "shader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>

Shader::Shader( const std::string &vertexSource, const std::string &fragmentSource ) :
   m_programHandle( 0 )
{
   m_programHandle = glCreateProgram();
   createFragmentShader( fragmentSource );
   createVertexShader( vertexSource );
   glLinkProgram( m_programHandle );
   checkLinkErrors();
}

Shader::Shader( const std::string &vertexSource, const std::string &geometrySource, const std::string &fragmentSource ) :
   m_programHandle( 0 )
{
   m_programHandle = glCreateProgram();
   createFragmentShader( fragmentSource );
   createGeometryShader( geometrySource );
   createVertexShader( vertexSource );
   glLinkProgram( m_programHandle );
   checkLinkErrors();
}

Shader::~Shader()
{
   glDeleteProgram( m_programHandle );
}

void Shader::applyUniform( ShaderVar v )
{
   GLuint loc = glGetUniformLocation( m_programHandle, static_cast<const GLchar*>( v.name.c_str() ) );

   switch( v.type )
   {
   case ShaderVar::FLOAT:
      glUniform1fv( loc, 1, (const GLfloat*) &v.val );
      break;
   case ShaderVar::VEC2:
      glUniform2fv( loc, 1, (const GLfloat*) &v.val );
      break;
   case ShaderVar::VEC3:
      glUniform3fv( loc, 1, (const GLfloat*) &v.val );
      break;
   case ShaderVar::VEC4:
      glUniform4fv( loc, 1, (const GLfloat*) &v.val );
      break;
   case ShaderVar::MAT2:
      glUniformMatrix2fv( loc, 1, false, (const GLfloat*) &v.val );
      break;
   case ShaderVar::MAT3:
      glUniformMatrix3fv( loc, 1, false, (const GLfloat*) &v.val );
      break;
   case ShaderVar::MAT4:
      glUniformMatrix4fv( loc, 1, false, (const GLfloat*) &v.val );
      break;
   case ShaderVar::TEX2D:
      bindTex2D( v.val.tex2D, loc );
      break;
   }
}

GLuint Shader::attrib( std::string name )
{
   return glGetAttribLocation( m_programHandle, name.c_str() );
}

void Shader::bindTex2D( Tex2D *tex, GLuint location )
{
    glUniform1i( location, 0 );
    glActiveTexture( GL_TEXTURE0 + 0 );
    tex->bind();
}

void Shader::checkLinkErrors()
{
   //Check for errors
   GLint link_status;
   glGetProgramiv( m_programHandle, GL_LINK_STATUS, &link_status );
   if( link_status==GL_FALSE )
   {
      //Make this more verbose later
      fprintf(stderr, "Error linking shader program: \n");

      char logBuf[1024];
      int len;
      glGetProgramInfoLog( m_programHandle, sizeof(logBuf), &len, logBuf );
      fprintf(stderr, "%s\n",logBuf);
   }
}

void Shader::createFragmentShader( const std::string &fragmentSource )
{
   GLuint fragmentShaderHandle = glCreateShader( GL_FRAGMENT_SHADER );
   createShader( fragmentShaderHandle, fragmentSource );
}

void Shader::createGeometryShader( const std::string &geometrySource )
{
   GLuint geometryShaderHandle = glCreateShader( GL_GEOMETRY_SHADER );
   createShader( geometryShaderHandle, geometrySource );
}

void Shader::createShader( GLuint handle, std::string source )
{
   if(!handle)
   {
      fprintf(stderr, "Error: Could not create shader.\n");
   }

   GLint status;
   const GLchar* codeArray[] = {source.c_str()};
   glShaderSource( handle, 1, codeArray, NULL );
   glCompileShader( handle );
   glGetShaderiv( handle, GL_COMPILE_STATUS, &status );
   if(status==GL_FALSE)
   {
       printCompileError( handle );
      return;
   }

   glAttachShader( m_programHandle, handle );
}

void Shader::printCompileError( GLuint handle )
{
    GLint maxLength = 0;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &maxLength);

    // The maxLength includes the NULL character
    std::vector<GLchar> errorLog(maxLength);
    glGetShaderInfoLog(handle, maxLength, &maxLength, &errorLog[0]);
    fprintf(stderr, "Shader compile error: %s\n", &errorLog[0] );
}

void Shader::createVertexShader( const std::string &vertexSource )
{
   GLuint vertexShaderHandle = glCreateShader( GL_VERTEX_SHADER );
   createShader( vertexShaderHandle, vertexSource );
}

void Shader::bind()
{
   glUseProgram( m_programHandle );
}

void Shader::unbind()
{
   glUseProgram( 0 );
}
