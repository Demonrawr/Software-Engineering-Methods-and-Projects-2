#include "shaderfilerepository.h"

#include <fstream>
#include <iostream>
#include <streambuf>

ShaderFileRepository::ShaderFileRepository()
{

}

std::string loadFileToString(std::ifstream &file)
{
   return std::string( (std::istreambuf_iterator<char>( file )), std::istreambuf_iterator<char>() );
}

void ShaderFileRepository::loadVertexShader( std::ifstream &file )
{
    m_data.vertexSource = loadFileToString( file );
    m_data.hasVertexSource = true;
}

void ShaderFileRepository::loadTessellationControlShader( std::ifstream &file )
{
    m_data.tessellationControlSource = loadFileToString( file );
    m_data.hasTessellationControlSource = true;
}

void ShaderFileRepository::loadTessellationEvaluationShader( std::ifstream &file )
{
    m_data.tessellationEvaluationSource = loadFileToString( file );
    m_data.hasTessellationEvaluationSource = true;
}

void ShaderFileRepository::loadGeometryShader( std::ifstream &file )
{
    m_data.geometrySource = loadFileToString( file );
    m_data.hasGeometrySource = true;
}

void ShaderFileRepository::loadFragmentShader( std::ifstream &file )
{
    m_data.fragmentSource = loadFileToString( file );
    m_data.hasFragmentSource = true;
}

std::vector<ShaderSourceData> ShaderFileRepository::getShaderSourceData()
{
    return std::vector<ShaderSourceData>( {m_data} );
}
