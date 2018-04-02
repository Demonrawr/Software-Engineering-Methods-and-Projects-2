#ifndef VBOATTRIBMARKER_H
#define VBOATTRIBMARKER_H

#include "GL/glew.h"
#include "engine/graphics/shaders/shader.h"

struct VBOAttribMarker
{
    enum DATA_TYPE{ FLOAT = GL_FLOAT, INT = GL_INT, UBYTE = GL_UNSIGNED_BYTE };
    enum DATA_NORMALIZE{ TRUE = GL_TRUE, FALSE = GL_FALSE };
    VBOAttribMarker( Shader::ATTRIB a, GLuint n, int o, DATA_TYPE t = FLOAT, bool normalize = false );

    Shader::ATTRIB attrib;
    DATA_TYPE dataType;
    DATA_NORMALIZE dataNormalize;
    GLuint numElements;
    size_t offset;
};

#endif // VBOATTRIBMARKER_H
