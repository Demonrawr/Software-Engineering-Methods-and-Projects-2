#ifndef SPRITEBATCHER_H
#define SPRITEBATCHER_H

#include <memory>
#include <vector>

#include "glm/glm.hpp"

class Tex2D;

namespace Graphics
{
    class FullScreenQuad;
}

class SpriteBatcher
{
public:
    SpriteBatcher();

    // Returns a sprite handle
    int registerSprite( Tex2D *tex );
    void clearSprites();
    void clearInstances();
    void queueSpriteInstance( int spriteHandle, const glm::mat4 &orientation );
    void drawSprites( class Shader* shader, const std::string &modelMatrixName, const std::string &texName );

private:
    std::unique_ptr<Graphics::FullScreenQuad> m_fsq;
    std::vector<Tex2D*> m_textures;
    std::vector<std::vector<glm::mat4>> m_instances;
};

#endif // SPRITEBATCHER_H
