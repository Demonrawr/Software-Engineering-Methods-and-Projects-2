#ifndef ORIENTATION2DUTILS
#define ORIENTATION2DUTILS

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "engine/physics/orientation2d.h"

glm::mat4 orientation2DToMat4( const Orientation2D &o )
{
    glm::mat4 m = glm::translate( glm::mat4( 1.0f ), glm::vec3( o.position, 0.0f ) );
    m = glm::rotate( m, o.angle, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    m = glm::scale( m, glm::vec3( o.scale ) );
    return m;
}

glm::mat4 dimsAndOrientation2DToMat4( const glm::vec2 &d, const Orientation2D &o)
{
    return orientation2DToMat4( o ) * glm::scale( glm::vec3( d, 1.0f ) );
}

#endif // ORIENTATION2DUTILS

