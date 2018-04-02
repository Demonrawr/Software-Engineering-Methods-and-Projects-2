#ifndef SIMPLESPRITE2D_H
#define SIMPLESPRITE2D_H

#include "sprite2d.h"
#include "simplesprite2ddata.h"

class SimpleSprite2D : public Sprite2D
{
public:
    SimpleSprite2D(const SimpleSprite2DData& data);


    glm::vec2 getDimensions() const;
    void setDimensions( const glm::vec2& dims );

    void setHandle(int h) { m_handle = h; }
    int getHandle() const;

private:
    glm::vec2 m_dimensions;
    int m_handle;
};


bool colliding( const SimpleSprite2D& a, const SimpleSprite2D& b );

#endif // SIMPLESPRITE2D_H
