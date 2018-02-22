#ifndef DOODLER_H
#define DOODLER_H

#include "engine/physics/orientation2d.h"

struct DoodlerSpriteBatcherHandleData
{
    int leftUp;
    int leftCrouch;
    int rightUp;
    int rightCrouch;
    int shootUp;
    int shootCrouch;
    int nozzle;
};

class Doodler
{
public:
    Doodler();

    enum class ANIMATION_STATE{ LEFT_UP, LEFT_CROUCH, RIGHT_UP, RIGHT_CROUCH, SHOOT_UP, SHOOT_CROUCH };

    void tick( float dt );
    void setVelocity( const glm::vec2& v );

    glm::vec2 getVelocity();
    ANIMATION_STATE getAnimationState() const;
    Orientation2D getOrientation() const;
    void setAnimationState( ANIMATION_STATE animationState );
    void setOrientation( const Orientation2D &orientation );

private:
    Orientation2D m_orientation;
    ANIMATION_STATE m_animationState;
    glm::vec2 m_velocity;
    float m_terminalFallVelocity;
};

#endif // DOODLER_H
