#include "spritebatcher.h"

#include "engine/graphics/primitives/fullscreenquad.h"
#include "engine/graphics/texture/texture2d.h"
#include "engine/physics/orientation2d.h"

SpriteBatcher::SpriteBatcher() :
    m_fsq( std::make_unique<Graphics::FullScreenQuad>() )
{

}

int SpriteBatcher::registerSprite( Tex2D *tex )
{
    m_textures.push_back( tex );
    m_instances.push_back(std::vector<glm::mat4>());
    return m_textures.size() - 1;
}

void SpriteBatcher::clearSprites()
{
    m_textures.clear();
    m_instances.clear();
}

void SpriteBatcher::clearInstances()
{
    for( auto it = m_instances.begin(); it != m_instances.end(); it++ )
    {
        (*it).clear();
    }
}

void SpriteBatcher::queueSpriteInstance( int spriteHandle, const glm::mat4 &modelMatrix )
{
    m_instances[ spriteHandle ].push_back( modelMatrix );
}

void SpriteBatcher::drawSprites(Shader* shader, const std::string& modelMatrixName, const std::string& texName)
{
    for( int i = 0; i < static_cast<int>(m_textures.size()); i++ )
    {
        Tex2D* tex = m_textures[ i ];
        shader->applyUniform(ShaderVar( tex, texName));
        for( int j = 0; j < static_cast<int>(m_instances[i].size()); j++ )
        {
            shader->applyUniform(ShaderVar(m_instances[i][j], modelMatrixName));
            m_fsq->draw();
        }
    }
}
