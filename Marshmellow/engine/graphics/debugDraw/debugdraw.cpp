#include "debugdraw.h"

#include "engine/graphics/shaders/shader.h"

DebugDraw::DebugDraw() :
     m_color( glm::vec3( 1.0f, 0.0784313725f, 0.705882353f ) ) // hot pink for debug
{
}

void DebugDraw::initGL()
{
    m_debugShader = new Shader( std::string( "data/shaders/debugDraw.vert" ), std::string( "data/shaders/debugDraw.frag" ) );
}
