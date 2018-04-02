#ifndef VAO_H
#define VAO_H

#include "GL/glew.h"
#include "engine/graphics/datatype/vbo.h"
#include "engine/graphics/datatype/vio.h"

class VAO
{
public:
    VAO();
    VAO( VBO vbo, int n = 0 );
    VAO( VBO vbo, VIO vio, int n = 0 );

    enum DRAW_METHOD { DRAW_ARRAYS, DRAW_INDEXED };

    void bind();
    void draw();
    void draw( int count );
    DRAW_METHOD drawMethod();
    void glDelete();
    void unbind();

private:
    DRAW_METHOD m_drawMethod;
    GLuint m_handle;
    GLuint m_numVertices;
    int m_size;
    VBO::GEOMETRY_LAYOUT m_triangleLayout;
//    VBO m_vbo;
//    VIO m_vio;
};

#endif // VAO_H
