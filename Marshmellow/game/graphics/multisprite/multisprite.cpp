#include "multisprite.h"

MultiSprite::MultiSprite( MultiSpriteData spriteMap ) :
    m_spriteMap( std::move( spriteMap ) ),
    m_state( m_spriteMap.states.begin()->first)
{
}

void MultiSprite::setState( const std::string& state )
{
    m_state = state;
}

std::string MultiSprite::getState() const
{
    return m_state;
}

std::vector<SimpleSprite2D> MultiSprite::getSpritesToDraw() const
{
    MultiSpriteState stateSpriteMap = m_spriteMap.states.at( m_state );
    std::vector<SimpleSprite2D> spritesToDraw;

    for(auto it = stateSpriteMap.sprites.begin(); it != stateSpriteMap.sprites.end(); it++ )
    {
        SimpleSprite2D sprite = readySubSprite( it->second );
        spritesToDraw.push_back( sprite );
    }

    return spritesToDraw;
}

Orientation2D MultiSprite::getOrientation() const
{
    return m_orientation;
}

void MultiSprite::setOrientation( const Orientation2D& o )
{
    m_orientation = o;
}

SimpleSprite2D MultiSprite::readySubSprite( const SimpleSprite2D &s ) const
{
    SimpleSprite2D sprite = s;
    auto o = sprite.getOrientation();
    o.position += getOrientation().position;
    o.angle += getOrientation().angle;
    sprite.setOrientation( o );
    return sprite;
}
