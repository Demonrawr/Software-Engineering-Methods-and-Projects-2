#include "texturecache.h"

TextureCache::TextureCache()
{

}

int TextureCache::storeTexture( Tex2D texture )
{
    if( m_emptySlots.size() == 0 )
    {
        m_textures.emplace_back( std::make_unique<Tex2D>( std::move( texture ) ) );
        return m_textures.size() - 1;
    }
    else
    {
        int index = m_emptySlots[ 0 ];
        m_textures[ index ] = std::make_unique<Tex2D>( std::move( texture ) );
        m_emptySlots[ 0 ] = m_emptySlots[ m_emptySlots.size() - 1 ];
        m_emptySlots.resize( m_emptySlots.size() - 1);
        return index;
    }
}

Tex2D* TextureCache::getTexture( int handle )
{
    return m_textures[ handle ].get();
}

void TextureCache::deleteTexture( int handle )
{
    m_textures[ handle ].reset();
    m_emptySlots.push_back( handle );
}
