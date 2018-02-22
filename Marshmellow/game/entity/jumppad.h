#ifndef JUMPPAD_H
#define JUMPPAD_H

#include "engine/physics/orientation2d.h"

class JumpPad
{
public:
    JumpPad(const glm::vec2& position);

    glm::vec2 getDimensions() const;
    Orientation2D getOrientation() const;

private:
    glm::vec2 m_dimensions;
    Orientation2D m_orientation;
};

#endif // JUMPPAD_H
