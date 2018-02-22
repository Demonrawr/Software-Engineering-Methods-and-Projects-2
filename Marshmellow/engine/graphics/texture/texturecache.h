#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <memory>
#include <vector>

#include "texture2d.h"

class TextureCache
{
public:
    TextureCache();

    int storeTexture( Tex2D );
    Tex2D* getTexture( int handle );
    void deleteTexture( int handle );

private:
    std::vector<std::unique_ptr<Tex2D>> m_textures;
    std::vector<int> m_emptySlots;
};

#endif // TEXTURECACHE_H
