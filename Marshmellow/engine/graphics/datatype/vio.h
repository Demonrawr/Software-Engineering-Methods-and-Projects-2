#ifndef VIO_H
#define VIO_H

#include <stdio.h>
#include <GL/glew.h>

class VIO
{
public:
    VIO( int* data, int size );

    void bind() const;
    void glDelete();
    void unbind() const;


private:
    GLuint m_handle;
};

#endif // VIO_H
