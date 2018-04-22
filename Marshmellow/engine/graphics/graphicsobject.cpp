#include "graphicsobject.h"

#include <cstdio>

#include "GL/glew.h"

GraphicsObject::GraphicsObject() :
    m_screenWidth( 500 ),
    m_screenHeight( 300 )
{
    initializeGLEW();
}

GraphicsObject::~GraphicsObject()
{
}

void GraphicsObject::setClearColor( float r, float g, float b, float a )
{
    glClearColor( r, g, b, a );
}

void GraphicsObject::clearColorBuffer()
{
    glClear( GL_COLOR_BUFFER_BIT );
}

void GraphicsObject::clearDepthBuffer()
{
    glClear( GL_DEPTH_BUFFER_BIT );
}

void GraphicsObject::checkError()
{
   switch( glGetError() )
   {
   case GL_NO_ERROR:
      fprintf(stderr, "GL_NO_ERROR\n");
      break;
   case GL_INVALID_ENUM:
      fprintf(stderr, "GL_INVALID_ENUM\n");
      break;
   case GL_INVALID_VALUE:
      fprintf(stderr, "GL_INVALID_VALUE\n");
      break;
   case GL_INVALID_FRAMEBUFFER_OPERATION:
      fprintf(stderr, "GL_INVALID_FRAMEBUFFER_OPERATION\n");
      break;
   case GL_OUT_OF_MEMORY:
      fprintf(stderr, "GL_OUT_OF_MEMORY\n");
      break;
   case GL_STACK_OVERFLOW:
      fprintf(stderr, "GL_STACK_OVERFLOW\n");
      break;
   case GL_STACK_UNDERFLOW:
      fprintf(stderr, "GL_STACK_UNDERFLOW\n");
      break;
   }
}

void GraphicsObject::cullFace( CULL_FACE c )
{
    switch( c )
    {
    case CULL_FACE::CULL_FRONT:
        glCullFace( GL_FRONT );
        break;
    case CULL_FACE::CULL_BACK:
        glCullFace( GL_BACK );
        break;
    case CULL_FACE::CULL_BOTH:
        glCullFace( GL_FRONT_AND_BACK );
        break;
    }
}

void GraphicsObject::disableBlend()
{
    glDisable( GL_BLEND );
}

void GraphicsObject::disableCullFace()
{
    glDisable( GL_CULL_FACE );
}

void GraphicsObject::disableDepth()
{
    glDisable( GL_DEPTH_TEST );
}

void GraphicsObject::disableDepthMask()
{
    glDepthMask( false );
}

void GraphicsObject::disableMultisample()
{
    glDisable( GL_MULTISAMPLE );
}

void GraphicsObject::enableBlend()
{
    glEnable( GL_BLEND );
}

void GraphicsObject::enableCullFace()
{
    glEnable( GL_CULL_FACE );
}

void GraphicsObject::enableDepth()
{
    glEnable( GL_DEPTH_TEST );
}

void GraphicsObject::enableDepthMask()
{
    glDepthMask( true );
}

void GraphicsObject::enableMultisample()
{
    glEnable( GL_MULTISAMPLE );
}

void GraphicsObject::setBlendMode( BLEND_MODE sFactor, BLEND_MODE dFactor )
{
    glBlendFunc( blendModeToEnum( sFactor ), blendModeToEnum( dFactor ) );
}

int GraphicsObject::blendModeToEnum( BLEND_MODE blendMode )
{
    switch( blendMode )
    {
    default:
    case BLEND_MODE::ZERO:
    return GL_ZERO;
    case BLEND_MODE::ONE:
    return GL_ONE;
    case BLEND_MODE::SRC_COLOR:
    return GL_SRC_COLOR;
    case BLEND_MODE::ONE_MINUS_SRC_COLOR:
    return GL_ONE_MINUS_SRC_COLOR;
    case BLEND_MODE::DST_COLOR:
    return GL_DST_COLOR;
    case BLEND_MODE::ONE_MINUS_DST_COLOR:
    return GL_ONE_MINUS_DST_COLOR;
    case BLEND_MODE::SRC_ALPHA:
    return GL_SRC_ALPHA;
    case BLEND_MODE::ONE_MINUS_SRC_ALPHA:
    return GL_ONE_MINUS_SRC_ALPHA;
    case BLEND_MODE::DST_ALPHA:
    return GL_DST_ALPHA;
    case BLEND_MODE::ONE_MINUS_DST_ALPHA:
    return GL_ONE_MINUS_DST_ALPHA;
    case BLEND_MODE::CONSTANT_COLOR:
    return GL_CONSTANT_COLOR;
    case BLEND_MODE::ONE_MINUS_CONSTANT_COLOR:
    return GL_ONE_MINUS_CONSTANT_COLOR;
    case BLEND_MODE::CONSTANT_ALPHA:
    return GL_CONSTANT_ALPHA;
    case BLEND_MODE::ONE_MINUS_CONSTANT_ALPHA:
    return GL_ONE_MINUS_CONSTANT_ALPHA;
    case BLEND_MODE::ALPHA_SATURATE:
    return GL_SRC_ALPHA_SATURATE;
    case BLEND_MODE::SRC1_COLOR:
    return GL_SRC1_COLOR;
    case BLEND_MODE::ONE_MINUS_SRC1_COLOR:
    return GL_ONE_MINUS_SRC1_COLOR;
    case BLEND_MODE::SRC1_ALPHA:
    return GL_SRC1_ALPHA;
    case BLEND_MODE::ONE_MINUS_SRC1_ALPHA:
    return GL_ONE_MINUS_SRC1_ALPHA;
    }
}

glm::ivec2 GraphicsObject::getScreenDimensions()
{
    return glm::ivec2( m_screenWidth, m_screenHeight );
}

void GraphicsObject::resize(int w, int h)
{
    m_screenWidth = w;
    m_screenHeight = h;

    glViewport( 0, 0, m_screenWidth, m_screenHeight );
}

void GraphicsObject::setLineWidth(float f )
{
    glLineWidth( f );
}

void GraphicsObject::setPolygonMode( POLYGON_MODE m )
{
    switch( m )
    {
    case POLYGON_MODE::POINT:
        glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
        break;
    case POLYGON_MODE::LINE:
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        break;
    case POLYGON_MODE::FILL:
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        break;
    }
}

void GraphicsObject::initializeGLEW()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
}

void GraphicsObject::printGLVersionInfo()
{
    fprintf( stderr, "Using OpenGL Version: %s\n", glGetString( GL_VERSION ) );
}
