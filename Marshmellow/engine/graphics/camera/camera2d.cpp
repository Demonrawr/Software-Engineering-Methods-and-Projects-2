#include "camera2d.h"

#include "glm/gtc/matrix_transform.hpp"

Camera2D::Camera2D(float width, float height) :
    m_aspectRatio( 1.0f ),
    m_height( height ),
    m_width( width )
{
}

Camera2D::~Camera2D(){}

float Camera2D::getAspectRatio() const
{
    return m_aspectRatio;
}

glm::mat4 Camera2D::getProjectionMatrix() const
{
    float x = m_position.x;
    float y = m_position.y;
    m_projectionMatrix = glm::ortho( x-m_width/2, x+m_width/2, y-m_height/2, y+m_height/2, -1.0f, 1.0f );
    return m_projectionMatrix;
}

glm::mat4 Camera2D::getViewMatrix() const
{
    m_viewMatrix = glm::mat4( 1.0f );
//    m_viewMatrix = glm::translate( m_viewMatrix, glm::vec3( m_width * 0.5f, m_height * 0.5f, 0.0f ) );
    return m_viewMatrix;
}

void Camera2D::setViewport(float l, float r, float b, float t)
{
    m_l = l;
    m_r = r;
    m_b = b;
    m_t = t;
}

float Camera2D::getHeight() const
{
    return m_height;
}

float Camera2D::getWidth() const
{
    return m_width;
}

void Camera2D::setHeight( float h )
{
    m_height = h;
}

void Camera2D::setWidth( float w )
{
    m_width = w;
}

void Camera2D::setPosition( const glm::vec2& pos )
{
    m_position = pos;
}

glm::vec2 Camera2D::getPosition() const
{
    return m_position;
}
