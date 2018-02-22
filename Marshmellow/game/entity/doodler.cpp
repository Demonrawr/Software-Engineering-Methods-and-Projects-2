#include "doodler.h"

#include <algorithm>

Doodler::Doodler() :
    m_terminalFallVelocity( -20.0f )
{

}

void Doodler::tick(float dt)
{
    float acceleration = -9.8f;
    float yvel = m_velocity.y;
    yvel += 0.5f*acceleration * dt;
    yvel = std::max( m_terminalFallVelocity, yvel );
    m_orientation.position += glm::vec2(m_velocity.x, yvel ) * dt;
    m_velocity.y = yvel;
}

glm::vec2 Doodler::getVelocity()
{
    return m_velocity;
}

void Doodler::setVelocity( const glm::vec2 &velocity )
{
    m_velocity = velocity;
}

Doodler::ANIMATION_STATE Doodler::getAnimationState() const
{
    return m_animationState;
}

Orientation2D Doodler::getOrientation() const
{
    return m_orientation;
}

void Doodler::setAnimationState(ANIMATION_STATE animationState)
{
    m_animationState = animationState;
}

void Doodler::setOrientation( const Orientation2D &orientation )
{
    m_orientation = orientation;
}
