#include "simplesprite2d.h"

SimpleSprite2D::SimpleSprite2D(const SimpleSprite2DData& data) :
    m_dimensions(data.dimensions),
    m_handle(data.handle)
{
    auto o = getOrientation();
    o.position.xy = data.offset;
    setOrientation( o );
}

int SimpleSprite2D::getHandle() const
{
    return m_handle;
}

void SimpleSprite2D::setDimensions( const glm::vec2& dims )
{
    m_dimensions = dims;
}

glm::vec2 SimpleSprite2D::getDimensions() const
{
    return m_dimensions;
}

bool colliding( const SimpleSprite2D& a, const SimpleSprite2D& b )
{
    auto aDims = a.getDimensions();
    auto aPos = a.getOrientation().position;
    auto bDims = b.getDimensions();
    auto bPos = b.getOrientation().position;

    return ( std::fabs(aPos.x - bPos.x) < (aDims.x + bDims.x) ) && ( std::fabs(aPos.y - bPos.y) < (aDims.y + bDims.y) );
}
