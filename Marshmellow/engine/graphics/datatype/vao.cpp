#include "vao.h"

#include "engine/graphics/datatype/vbo.h"

// This needs to go away somehow.
VAO::VAO() :
    m_drawMethod( DRAW_ARRAYS ),
    m_handle( 0 ),
    m_numVertices( 0 ),
    m_size( 0 ),
    m_triangleLayout( VBO::LAYOUT_TRIANGLES )
{

}

VAO::VAO( VBO vbo, int n ) :
    m_drawMethod( DRAW_ARRAYS ),
    m_handle( 0 ),
    m_numVertices( n ),
    m_size( 0 ),
    m_triangleLayout( vbo.triangleLayout() )
//    m_vbo( vbo ),
//    m_vio( VIO( 0, 0 ) )
{
    glGenVertexArrays( 1, &m_handle );
    glBindVertexArray( m_handle );
    vbo.bindAndEnable();
    glBindVertexArray( 0 );
    vbo.unbind();
}

VAO::VAO(VBO vbo, VIO vio , int n ) :
    m_drawMethod( DRAW_INDEXED ),
    m_handle( 0 ),
    m_numVertices( n ),
    m_size( 0 ),
    m_triangleLayout( vbo.triangleLayout() )
//    m_vbo( vbo ),
//    m_vio( vio )
{
    glGenVertexArrays( 1, &m_handle );
    glBindVertexArray( m_handle );
    vbo.bindAndEnable();
    vio.bind();
    glBindVertexArray( 0 );
    vio.unbind();
    vbo.unbind();
}

void VAO::draw()
{
    draw( m_numVertices );
}

void VAO::draw( int count )
{
    switch( m_drawMethod )
    {
    case VAO::DRAW_ARRAYS:
        glDrawArrays( m_triangleLayout, 0, count );
        break;
    case VAO::DRAW_INDEXED:
        glDrawElements( m_triangleLayout, count, GL_UNSIGNED_INT, 0 );
        break;
    }
}

void VAO::bind()
{
    glBindVertexArray( m_handle );
}

void VAO::glDelete()
{
    glDeleteBuffers( 1, &m_handle );
//    m_vbo.glDelete();
//    if( m_drawMethod == VAO::DRAW_INDEXED ) m_vio.glDelete();
}

void VAO::unbind()
{
    glBindVertexArray( 0 );
}
