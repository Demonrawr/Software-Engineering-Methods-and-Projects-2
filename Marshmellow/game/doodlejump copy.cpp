#include "doodlejump.h"

#include <fstream>
#include <iostream>

#include "engine/graphics/graphicsobject.h"
#include "engine/graphics/dataload/shaders/shaderfilerepository.h"
#include "engine/graphics/primitives/fullscreenquad.h"
#include "engine/graphics/shaders/shader.h"
#include "engine/graphics/sprite2d/spritebatcher.h"
#include "engine/graphics/texture/textureloader.h"
#include "engine/physics/orientation2dutils.h"

#include "game/graphics/DataParse/simplesprite2dfileparser.h"
#include "game/graphics/DataParse/multispritefileparser.h"
#include "engine/graphics/sprite2d/simplesprite2dfiledata.h"
#include "game/graphics/DataParse/multispritefiledata.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "tinyxml2.h"

DoodleJump::DoodleJump() :
//    m_oldTime( 0.0f ),
//    m_time( 0.0f ),
//    m_dt( 0.0f ),
//    m_moveSpeed( 5.0f ),
    m_camera( 800, 600 ),
    m_textureLoader( std::make_unique<TextureLoader>() )
{
    auto p = m_camera.getPosition();
    p.y += 2.0f;
    m_camera.setPosition( p );
}

DoodleJump::~DoodleJump()
{

}

//InputSelector& DoodleJump::getInputSelector()
//{
//    return m_inputSelector;
//}

void DoodleJump::initializeGraphics()
{
    m_graphicsObject = std::make_unique<GraphicsObject>();
    m_graphicsObject->printGLVersionInfo();
    m_spriteBatcher = std::make_unique<SpriteBatcher>();
    loadGraphicsAssets();
//    auto o = m_doodler.getOrientation();
//    o.position.x = lowestCurrentJumpPadPosition().x;
//    m_doodler.setOrientation( o );
}

//glm::vec2 DoodleJump::lowestCurrentJumpPadPosition()
//{
//    glm::vec2 p( 0.0f, 100000000000.0f );
//    for(int i = 0; i < m_jumpPads.size(); i++ )
//    {
//        glm::vec2 jp = m_jumpPads[ i ].getOrientation().position;
//        if( jp.y < p.y )
//            p = jp;
//    }
//    return p;
//}

void DoodleJump::loadGraphicsAssets()
{
    loadShaders();
    loadSprites();
}

void DoodleJump::loadShaders()
{
    ShaderFileRepository repo;
    std::ifstream vertFile( "shaders/sprite2d/sprite2d.vert" );
    std::ifstream fragFile( "shaders/sprite2d/sprite2d.frag" );
    repo.loadVertexShader( vertFile );
    repo.loadFragmentShader( fragFile );
    ShaderSourceData ssd = repo.getShaderSourceData()[0];
    m_shader = std::make_unique<Shader>( ssd.vertexSource, ssd.fragmentSource );
}

void DoodleJump::loadSprites()
{
    m_spriteBatcher->clearSprites();
    loadDoodlerSprite();
//    loadJumpPadSprite();
//    loadMovingJumpPadSprite();
    loadBackgroundSprite();
}

MultiSpriteData DoodleJump::multiSpriteFileDataToMultiSpriteData( const MultiSpriteFileData& fdata )
{
    MultiSpriteData data;

    for( auto it = fdata.states.begin(); it != fdata.states.end(); it++ )
    {
        std::string stateName = it->first;
        MultiSpriteStateFileData state = it->second;
        for( auto it2 = state.sprites.begin(); it2 != state.sprites.end(); it2++ )
        {
            std::string spriteName = it2->first;
            SimpleSprite2DFileData ssfileData = it2->second;
            data.states[ stateName ].sprites.emplace( spriteName, spriteFileDataToSpriteData( ssfileData ) );
        }
    }

    return data;
}

void DoodleJump::loadBackgroundSprite()
{
    m_backgroundSpriteData = spriteFileDataToSpriteData( pathToSimpleSprite2DFileData( "sprites/Background.xml" ) );
    m_backgroundSprite = std::make_unique<SimpleSprite2D>( m_backgroundSpriteData );
}

void DoodleJump::loadDoodlerSprite()
{
    MultiSpriteFileData fdata = pathToMultiSpriteFileData( "sprites/Doodler.xml" );
    std::string setState = "LeftUp";
    if( m_doodlerSprite )
    {
        setState = m_doodlerSprite->getState();
    }
    m_doodlerSpriteData = multiSpriteFileDataToMultiSpriteData( fdata );

    m_doodlerSprite = std::make_unique<MultiSprite>( m_doodlerSpriteData );
    m_doodlerSprite->setState( setState );
}

int DoodleJump::texPathToSpriteHandle( const std::string &path )
{
    TextureParams p;
    Tex2D tex = m_textureLoader->loadTex2D( path, p );
    int texHandle = m_textureCache.storeTexture( std::move( tex ) );
    return m_spriteBatcher->registerSprite( m_textureCache.getTexture( texHandle ) );
}

SimpleSprite2DData DoodleJump::spriteFileDataToSpriteData( const SimpleSprite2DFileData& d)
{
    SimpleSprite2DData data;
    data.dimensions = d.dimensions;
    data.offset = d.offset;
    data.handle = texPathToSpriteHandle( d.path );
    return data;
}

//void DoodleJump::loadJumpPadSprite()
//{
//    SimpleSprite2DFileData d = pathToSimpleSprite2DFileData( "sprites/JumpPad.xml" );
//    m_jumpPadSpriteData = spriteFileDataToSpriteData( d );

//    refreshJumpPadSprites();
//}

//void DoodleJump::refreshJumpPadSprites()
//{
//    std::vector<SimpleSprite2D> newJumpPads;
//    for( int i = 0; i < m_numJumpPads; i++ )
//    {
//        newJumpPads.push_back( SimpleSprite2D( m_jumpPadSpriteData ) );
//        Orientation2D o = newJumpPads[ i ].getOrientation();
//        o.position.y = -10.0f;
//        newJumpPads[ i ].setOrientation( o );
//    }
//    auto oldSize = m_jumpPads.size();
//    m_jumpPads = newJumpPads;
//    if( oldSize == 0 )
//        updateJumpPads();
//}

//void DoodleJump::loadMovingJumpPadSprite()
//{


//}

void DoodleJump::drawFrame()
{
    clearScreen();
    setBlendState();
    setCameraState();
    queueSprites();
    drawSprites();
}

void DoodleJump::resize( Rect2D<int> dims )
{
    glViewport( 0, 0, dims.width, dims.height );

    float gameWidth = 5.0f;
    float ratio = static_cast<float>( dims.height ) / static_cast<float>( dims.width );
    m_camera.setHeight( ratio*gameWidth );
    m_camera.setWidth( gameWidth );
}

void DoodleJump::tick(float dt )
{
// BEGIN TA SOLUTION
//    updateTime( dt );
//    updatePageBottom();
//    processInputs();
//    applyControls();
//    updateGame();
// END TA SOLUTION
}

//void DoodleJump::updateTime( float dt )
//{
// BEGIN TA SOLUTION
//    m_oldTime = m_time;
//    m_time += dt;
//    m_dt = dt;
// END TA SOLUTION
//}

//void DoodleJump::updatePageBottom()
//{
//    m_pageBottom = m_camera.getPosition().y - m_camera.getHeight() / 2.0f;
//}

//void DoodleJump::processInputs()
//{
//    m_playerCommands = m_inputMapper.keysToCommands( m_inputSelector );
//}

//void DoodleJump::applyControls()
//{
//    if( m_playerCommands.shoot )
//    {
//        m_doodlerSprite->setState( "Shoot" );
//    }
//    else if( m_playerCommands.moveLeft && !m_playerCommands.moveRight )
//    {
//        m_doodlerSprite->setState("LeftUp");
//    }
//    else if( !m_playerCommands.moveLeft && m_playerCommands.moveRight )
//    {
//        m_doodlerSprite->setState("RightUp");
//    }

//    glm::vec2 v = m_doodler.getVelocity();
//    v.x = -m_moveSpeed * (  m_playerCommands.moveLeft ) +
//           m_moveSpeed * (  m_playerCommands.moveRight );
//    m_doodler.setVelocity( v );

//    if( m_playerCommands.reloadSprites )
//            loadSprites();
//}

void DoodleJump::clearScreen()
{
    m_graphicsObject->enableDepth();
    m_graphicsObject->setClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    m_graphicsObject->clearColorBuffer();
    m_graphicsObject->clearDepthBuffer();
}

void DoodleJump::setBlendState()
{
    m_graphicsObject->enableBlend();
    m_graphicsObject->setBlendMode( GraphicsObject::BLEND_MODE::SRC_ALPHA, GraphicsObject::BLEND_MODE::ONE_MINUS_SRC_ALPHA );
}

void DoodleJump::setCameraState()
{
//    auto cpos = m_camera.getPosition();
//    cpos.y = std::max( m_doodler.getOrientation().position.y, cpos.y );
//    m_camera.setPosition( cpos );
}

void DoodleJump::queueBackgroundSprite()
{
    auto o = m_backgroundSprite->getOrientation();
    o.position = m_camera.getPosition();
    m_backgroundSprite->setOrientation( o );
    float width = 5.0f;
    float height = width * m_camera.getAspectRatio();
    glm::mat4 m = orientation2DToMat4( o );
    m = m * glm::scale( glm::vec3( width, height, 1.0f ) );
    m_spriteBatcher->queueSpriteInstance( m_backgroundSprite->getHandle(), m );
}

void DoodleJump::queueSprites()
{
    m_spriteBatcher->clearInstances();
    queueBackgroundSprite();
//    queueJumpPadSprites();
    queueDoodlerSprite();
}

void DoodleJump::drawSprites()
{
    m_shader->bind();
    m_shader->applyUniform( ShaderVar( m_camera.getViewMatrix(), "viewMatrix" ) );
    m_shader->applyUniform( ShaderVar( m_camera.getProjectionMatrix(), "projectionMatrix" ) );

    m_spriteBatcher->drawSprites( m_shader.get(), "modelMatrix", "texMap" );

    m_shader->unbind();
}

void DoodleJump::queueDoodlerSprite()
{
//    Orientation2D doodlerOrientation = m_doodler.getOrientation();

//    m_doodlerSprite->setOrientation( doodlerOrientation );
    std::vector<SimpleSprite2D> doodlerSprites = m_doodlerSprite->getSpritesToDraw();
    for( int i = 0; i < doodlerSprites.size(); i++ )
    {
        SimpleSprite2D sprite = doodlerSprites[ i ];
        glm::mat4 model = dimsAndOrientation2DToMat4( sprite.getDimensions(), sprite.getOrientation() );
        m_spriteBatcher->queueSpriteInstance( sprite.getHandle(), model );
    }
}

//void DoodleJump::queueJumpPadSprites()
//{
//    for(int i = 0; i < m_jumpPads.size(); i++ )
//    {
//        SimpleSprite2D& j = m_jumpPads[ i ];
//        Orientation2D o = j.getOrientation();
//        glm::mat4 m = orientation2DToMat4( o );

//        m = m * glm::scale(glm::vec3(j.getDimensions(), 1.0f));
//        m_spriteBatcher->queueSpriteInstance( j.getHandle(), m );
//    }
//}

//void DoodleJump::queueMovingJumpPadSprites()
//{

//}

//void DoodleJump::updateGame()
//{
//    updateJumpPads();
//    m_doodler.tick( m_dt );
////    if( m_doodler.getVelocity().y <= 0 )
//    {
//        handleDoodlerJumpPadCollisions();
//    }
//    if( doodlerFellThroughBottom() )
//    {
//        m_gameState = GAME_STATE::GAME_OVER;
//    }
//    updateScore();

//}

//void DoodleJump::updateJumpPads()
//{
//    for( int i = 0; i < m_jumpPads.size(); i++ )
//    {
//        Orientation2D o = m_jumpPads[ i ].getOrientation();
//        if( o.position.y < m_pageBottom )
//        {
//            o.position = nextJumpPadPosition();
//            m_jumpPads[ i ].setOrientation( o );
//        }
//    }
//}

//float RandomFloat(float a, float b) {
//    float random = ((float) rand()) / (float) RAND_MAX;
//    float diff = b - a;
//    float r = random * diff;
//    return a + r;
//}

//glm::vec2 DoodleJump::nextJumpPadPosition()
//{
//    glm::vec2 p;
//    p.y = m_lastJumpPadHeight + m_jumpPadSpacing;
//    p.x = RandomFloat( -2.5f, 2.5f );
//    m_lastJumpPadHeight += m_jumpPadSpacing;
//    return p;
//}

//void DoodleJump::handleDoodlerJumpPadCollisions()
//{
//    if( m_doodler.getVelocity().y > 0.0f )
//        return;

//    for(int i = 0; i < m_jumpPads.size(); i++ )
//    {
//        SimpleSprite2D& jp = m_jumpPads[ i ];
//        std::vector<SimpleSprite2D> doodlerSprites = m_doodlerSprite->getSpritesToDraw();
//        for( int j = 0; j < doodlerSprites.size(); j++ )
//        {
//            SimpleSprite2D ds = doodlerSprites[ j ];
//            if( colliding( ds, jp) && jp.getOrientation().position.y < ds.getOrientation().position.y )
//            {
//                glm::vec2 v = m_doodler.getVelocity();
//                v.y = +5.0f;
//                m_doodler.setVelocity( v );
//            }
//        }
//    }
//}

//bool DoodleJump::doodlerFellThroughBottom()
//{
//    return m_doodler.getOrientation().position.y <= m_pageBottom;
//}

//void DoodleJump::updateScore()
//{

//}
