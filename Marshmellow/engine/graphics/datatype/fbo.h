#ifndef FBO_H
#define FBO_H

#include <vector>

#include "GL/glew.h"

#include "glm/glm.hpp"

#include "engine/graphics/texture/texture.h"

class FBO
{
public:
    FBO( glm::ivec2 dims = glm::vec2( 512, 512 ) );
    ~FBO();

    int addColorAttachment();
    void addDepthAttachment();

    void bind();

    Texture2D getColorAttachment( unsigned int index );
    Texture2D getDepthAttachment();
    glm::ivec2 getDimensions();

    void unbind();

private:
    std::vector<Texture2D> m_colorAttachments;
    Texture2D m_depthAttachment;
    glm::ivec2 m_dimensions;

    GLuint m_fbo;

};

#endif // FBO_H
