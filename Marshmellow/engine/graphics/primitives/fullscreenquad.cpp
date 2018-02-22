#include "fullscreenquad.h"

#include "GL/glew.h"
#include "engine/graphics/shaders/shader.h"
#include "engine/graphics/datatype/vboattribmarker.h"
#include "engine/graphics/datatype/vbo.h"

Graphics::FullScreenQuad::FullScreenQuad()
{
    // Face vertices
    const int dataSize = 8*4;
    GLfloat data[dataSize] = { -1.0f,  1.0f,  0.0f,      0.0f, 0.0f, 1.0f,       0.0f, 1.0f,
                               -1.0f, -1.0f,  0.0f,      0.0f, 0.0f, 1.0f,       0.0f, 0.0f,
                                1.0f,  1.0f,  0.0f,      0.0f, 0.0f, 1.0f,       1.0f, 1.0f,
                                1.0f, -1.0f,  0.0f,      0.0f, 0.0f, 1.0f,       1.0f, 0.0f};

    // Sync VBO with VAO
    std::vector< VBOAttribMarker > attribs;
    attribs.push_back( VBOAttribMarker( Shader::ATTRIB_POSITION,  3, 0 ) );
    attribs.push_back( VBOAttribMarker( Shader::ATTRIB_NORMAL,    3, 3 * sizeof( GLfloat ) ) );
    attribs.push_back( VBOAttribMarker( Shader::ATTRIB_TEXCOORD0, 2, ( 3 + 3 ) * sizeof( GLfloat ) ) );
    VBO vbo = VBO( data, dataSize, attribs, VBO::LAYOUT_TRIANGLE_STRIP );
    m_vao = VAO( vbo, 4 );
}

Graphics::FullScreenQuad::~FullScreenQuad()
{

}

void Graphics::FullScreenQuad::draw()
{
    m_vao.bind();
    m_vao.draw();
    m_vao.unbind();
}
