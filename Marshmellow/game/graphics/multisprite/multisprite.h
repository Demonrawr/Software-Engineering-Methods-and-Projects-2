#ifndef MULTISPRITE_H
#define MULTISPRITE_H

#include <map>
#include <string>
#include <vector>

#include "engine/graphics/sprite2d/sprite2d.h"
#include "engine/graphics/sprite2d/simplesprite2d.h"

struct MultiSpriteState
{
    std::map<std::string,SimpleSprite2D> sprites;
};

struct MultiSpriteData
{
    std::map<std::string, MultiSpriteState> states;
};

class MultiSprite
{
public:
    MultiSprite( MultiSpriteData );

    Orientation2D getOrientation() const;
    void setOrientation( const Orientation2D& o );

    void setState( const std::string& state );
    std::string getState() const;
    std::vector<SimpleSprite2D> getSpritesToDraw() const;

private:
    MultiSpriteData m_spriteMap;
    std::string m_state;
    Orientation2D m_orientation;

    SimpleSprite2D readySubSprite( const SimpleSprite2D& s ) const;
};

#endif // MULTISPRITE_H
