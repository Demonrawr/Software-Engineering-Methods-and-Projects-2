#include "vbo.h"

VBO::VBO( const float *data, int size, std::vector<VBOAttribMarker> markers, GEOMETRY_LAYOUT t ) :
    m_handle( -1 ),
    m_markers( markers ),
    m_size( size ),
    m_stride( 0 ),
    m_triangleLayout ( t )
{
    glGenBuffers( 1, &m_handle );
    glBindBuffer( GL_ARRAY_BUFFER, m_handle );
    glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), &data[0], GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

    for( unsigned int i = 0; i < m_markers.size(); i++ )
    {
        m_stride += m_markers[i].numElements;
    }
    m_stride *= sizeof( GLfloat );
}

//VBO::VBO( const VBO &vbo ) :
//    m_handle( vbo.m_handle ),
//    m_markers( vbo.m_markers ),
//    m_size( vbo.m_size ),
//    m_stride( vbo.m_stride ),
//    m_triangleLayout( vbo.m_triangleLayout )
//{

//}

void VBO::bind() const
{
    glBindBuffer( GL_ARRAY_BUFFER, m_handle );
}

void VBO::bindAndEnable() const
{
    bind();
    for( unsigned int i = 0; i < m_markers.size(); i ++ )
    {
        VBOAttribMarker am = m_markers[i];
        glEnableVertexAttribArray( am.attrib );
        glVertexAttribPointer( am.attrib, am.numElements, am.dataType, am.dataNormalize, m_stride, (GLvoid*)am.offset );
    }
}

void VBO::glDelete()
{
    glDeleteBuffers( 1, &m_handle );
}

VBO::GEOMETRY_LAYOUT VBO::triangleLayout() const
{
    return m_triangleLayout;
}

void VBO::unbind() const
{
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
}
