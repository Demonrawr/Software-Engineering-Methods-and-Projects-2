#ifndef VBO_H
#define VBO_H

#include <vector>
#include "GL/glew.h"
#include "engine/graphics/datatype/vboattribmarker.h"

class VBO
{
public:
    enum GEOMETRY_LAYOUT { LAYOUT_TRIANGLES = GL_TRIANGLES,
                           LAYOUT_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
                           LAYOUT_TRIANGLE_FAN = GL_TRIANGLE_FAN,
                           LAYOUT_LINE_STRIP = GL_LINE_STRIP };

    VBO( const float *data, int size, std::vector<VBOAttribMarker> markers, GEOMETRY_LAYOUT t = LAYOUT_TRIANGLES );
//    VBO( const VBO &vbo );


    void bind() const;
    void bindAndEnable() const;
    void glDelete();
    GEOMETRY_LAYOUT triangleLayout() const;
    void unbind() const;

private:
    GLuint m_handle;
    std::vector<VBOAttribMarker> m_markers;
    int m_size;
    GLuint m_stride;
    GEOMETRY_LAYOUT m_triangleLayout;
};

#endif // VBO_H
