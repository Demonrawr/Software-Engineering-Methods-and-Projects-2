#include "fbo.h"
#include "engine/graphics/graphicsobject.h"

FBO::FBO( glm::ivec2 dims ) :
    m_dimensions( dims )
{
    glGenFramebuffers( 1, &m_fbo );
    m_depthAttachment.handle = 0;
}

FBO::~FBO()
{
    // Delete all the textures
    // Delete the FBO
}

int FBO::addColorAttachment()
{
    bind();

        int index = m_colorAttachments.size();
        Texture2D tex;
        glGenTextures( 1, &tex.handle );
        glBindTexture( GL_TEXTURE_2D, tex.handle );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, m_dimensions.x, m_dimensions.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL );
        glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, GL_TEXTURE_2D, tex.handle, 0);

        m_colorAttachments.push_back( tex );

        GLenum fragOuts[ m_colorAttachments.size() ];
        for( unsigned int i = 0; i < m_colorAttachments.size(); i++ )
        {
            fragOuts[ i ] = GL_COLOR_ATTACHMENT0 + i;
        }
        glDrawBuffers( m_colorAttachments.size(), fragOuts );

    unbind();

    glBindTexture( GL_TEXTURE_2D, 0 );
    return tex.handle;
}

void FBO::addDepthAttachment()
{
    assert( m_depthAttachment.handle == 0 );

    bind();

    glGenTextures( 1, &m_depthAttachment.handle );
    glBindTexture( GL_TEXTURE_2D, m_depthAttachment.handle );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );

    glFramebufferTexture2D( GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_depthAttachment.handle, 0 );


    unbind();
}

void FBO::bind()
{
    assert( m_fbo != 0 );
    glBindFramebuffer( GL_FRAMEBUFFER, m_fbo );
}

Texture2D FBO::getColorAttachment( unsigned int index )
{
    return m_colorAttachments[ index ];
}

Texture2D FBO::getDepthAttachment()
{
    return m_depthAttachment;
}

glm::ivec2 FBO::getDimensions()
{
    return m_dimensions;
}

void FBO::unbind()
{
    glBindFramebuffer( GL_FRAMEBUFFER, 0 );
}
