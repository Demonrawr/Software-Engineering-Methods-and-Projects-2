#include "doodlejump.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <QDebug>
#include <math.h>
#include "engine/graphics/graphicsobject.h"
#include "engine/graphics/dataload/shaders/shaderfilerepository.h"
#include "engine/graphics/primitives/fullscreenquad.h"
#include "engine/graphics/shaders/shader.h"
#include "engine/graphics/sprite2d/spritebatcher.h"
#include "engine/graphics/texture/textureloader.h"
#include "engine/physics/orientation2dutils.h"
#include "game/entity/doodler.h"
#include "game/graphics/DataParse/simplesprite2dfileparser.h"
#include "game/graphics/DataParse/multispritefileparser.h"
#include "engine/graphics/sprite2d/simplesprite2dfiledata.h"
#include "game/graphics/DataParse/multispritefiledata.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "tinyxml2.h"

Marshmellow::Marshmellow() :
   m_camera( 800, 600 ),
   m_textureLoader( std::make_unique<TextureLoader>() ),
   m_gameWidth( 5.0f ),
   m_score( 0 )
{
   auto p = m_camera.getPosition();
   p.y += 2.0f;
   m_camera.setPosition( p );
}

Marshmellow::~Marshmellow()
{

}

void Marshmellow::startButtonPressed()
{
    initvelocity = .2;
}

void Marshmellow::restartButtonPressed()
{//need to fix restart button so that the character resets in the correct position
    resetVariables();
    setBlendState();
    setCameraState();
    loadSprites();
    queueSprites();
    drawSprites();
}

void Marshmellow::resetVariables(){
    m_score = 0;
    auto c = m_camera.getPosition();
    c.y = 1;
    c.x = 0;
    velocity = 0;
    timer = 0;
    auto p = m_doodlerSprite->getOrientation();
    p.position.x = 0;
    p.position.y = 2;
    m_doodlerSprite->setOrientation(p);
    JumpPadBuffer.clear();
    m_camera.setPosition(c);
}

void Marshmellow::pauseButtonPressed()
{
   // TODO
}

void Marshmellow::loadSprites()
{
   srand(time(0));
   m_spriteBatcher->clearSprites();
   loadJumpPad();
   loadMovingJump();
   Marshmellow::generatejumppad();
   loadDoodlerSprite();
   loadBackgroundSprite();
   // TODO: Load more sprites here
}

void Marshmellow::loadBackgroundSprite()
{
   // Load Sprite2D files to Sprite2D data structs
   // Turn Sprite2D data structs into Sprite2D objects
   m_backgroundSpriteData = spriteFileDataToSpriteData( pathToSimpleSprite2DFileData( "sprites/Background.xml" ) );
   m_backgroundSprite = std::make_unique<SimpleSprite2D>( m_backgroundSpriteData );
}
void Marshmellow::loadJumpPad()
{
   m_jumppadSpriteData = spriteFileDataToSpriteData( pathToSimpleSprite2DFileData( "sprites/JumpPad.xml" ) );
   m_jumppadSprite = std::make_unique<SimpleSprite2D>( m_jumppadSpriteData );
}
void Marshmellow::loadMovingJump(){
    m_jumpMoveSpriteData = spriteFileDataToSpriteData( pathToSimpleSprite2DFileData( "sprites/JumpPad2.xml" ) );
    m_jumpMoveSprite = std::make_unique<SimpleSprite2D>( m_jumpMoveSpriteData );
}

void Marshmellow::loadDoodlerSprite()
{
   // Load MultiSprite files to multisprite data structs
   // Turn multisprite data structs into MultiSprites
   // Give it an initial state if you want
   MultiSpriteFileData fdata = pathToMultiSpriteFileData( "sprites/Doodler.xml" );
   std::string setState = "RightUp";
   if( m_doodlerSprite )
   {
       setState = m_doodlerSprite->getState();
   }
   m_doodlerSpriteData = multiSpriteFileDataToMultiSpriteData( fdata );
   m_doodlerSprite = std::make_unique<MultiSprite>( m_doodlerSpriteData );
   m_doodlerSprite->setState( setState );
}

void Marshmellow::drawFrame()
{
   // Don't change this
   clearScreen();
   setBlendState();

   // This shouldn't need modification, either
   setCameraState();
   queueSprites();
   drawSprites();
}



void Marshmellow::tick(float dt )
{
   auto p = m_doodlerSprite->getOrientation(); //Jump Physics
   velocity = initvelocity + ((-4.8)*timer);
   double height = velocity+(0.5*(-4.8)*timer);
   timer+=.001;
   p.position.y += height;
   m_doodlerSprite->setOrientation(p);
   padMovement();
   for ( int i = 0; i < JumpPadBuffer.size(); i++){ //Collision
       SimpleSprite2D pad = JumpPadBuffer[i];
       if (colliding(m_doodlerSprite->getSpritesToDraw().back(), pad) && velocity<=0){
           timer = 0;
           velocity = 0;
           m_doodlerSprite->setState("RightDown");
           m_score += 2;
       }
   }
   if (p.position.y < (m_camera.getPosition().y-5)){ //Drop
       qDebug() << "Lost" << endl;
   }
   doodleMovement();

}
void Marshmellow::padMovement(){
    for ( int i = 0; i < JumpPadBuffer.size(); i++){ //Collision
        auto m = JumpPadBuffer[i].getOrientation();
        if (m_score>1000){
            m.position.x += -.15;
        } else if (m_score>900){
            m.position.x += -.14;
        }
          else if (m_score>800){
            m.position.x += -.13;
        }
          else if (m_score>700){
            m.position.x += -.12;
        }
          else if (m_score>600){
            m.position.x += -.11;
        }
          else if (m_score>500){
            m.position.x += -.1;
        }
          else if (m_score>400){
            m.position.x += -.08;
        }
          else if (m_score>300){
            m.position.x += -.06;
        }
          else if (m_score>200){
            m.position.x += -.04;
        }

          else if (m_score>100){
            m.position.x += -.02;
        } else {
            m.position.x += -.01;
        }
        JumpPadBuffer[i].setOrientation(m);
        if (JumpPadBuffer[i].getOrientation().position.x < (m_camera.getPosition().x-3.5)){
            m.position.x += 7;
            JumpPadBuffer[i].setOrientation(m);
            }
    }
}

void Marshmellow::doodleMovement(){
    if(command.moveLeft == true)
        {
            orientation.position.x = orientation.position.x + -0.1f;
            orientation.position.y = m_doodlerSprite->getOrientation().position.y;
            if(orientation.position.x < -2.6)
                orientation.position.x += 5.0;
            m_doodlerSprite->setState("LeftUp");
            m_doodlerSprite->setOrientation(orientation);
        }
        if(command.moveRight == true)
        {
            orientation.position.x = orientation.position.x + 0.1f;
            orientation.position.y = m_doodlerSprite->getOrientation().position.y;
            if(orientation.position.x > 2.6)
                orientation.position.x += -5.0;
            m_doodlerSprite->setState("RightUp");
            m_doodlerSprite->setOrientation(orientation);
        }
}

void Marshmellow::setCameraState()
{
    /*
   auto p = m_doodlerSprite->getOrientation().position;
      if (p.y > (m_camera.getPosition().y+10)){
             auto c = m_camera.getPosition();
             c.y += 2;
             m_camera.setPosition(c);
      }
      else if (p.y > (m_camera.getPosition().y+8)){
          auto c = m_camera.getPosition();
          c.y += 0.9;
          m_camera.setPosition(c);
      }
      else if (p.y > (m_camera.getPosition().y+6)) {
          auto c = m_camera.getPosition();
          c.y += 0.2;
          m_camera.setPosition(c);
      }
      else if (p.y > (m_camera.getPosition().y+4)) {
          auto c = m_camera.getPosition();
          c.y += 0.06;
          m_camera.setPosition(c);
      }
      else if (p.y > (m_camera.getPosition().y+1)) {
          auto c = m_camera.getPosition();
          c.y += 0.03;
          m_camera.setPosition(c);
      }
      */
}

void Marshmellow::queueBackgroundSprite()
{
   auto o = m_backgroundSprite->getOrientation();
   o.position = m_camera.getPosition();
   m_backgroundSprite->setOrientation( o );
   float width = m_gameWidth;
   float height = width * m_camera.getAspectRatio();
   glm::mat4 m = orientation2DToMat4( o );
   m = m * glm::scale( glm::vec3( width, height, 1.0f ) );
   m_spriteBatcher->queueSpriteInstance( m_backgroundSprite->getHandle(), m );
}
void Marshmellow::queueInitialJumpPadSprite()
{
    auto o = m_jumppadSprite->getOrientation();
    o.position.x = 0;
    o.position.y = 0;
    m_jumppadSprite->setOrientation(o);
    glm::mat4 mod = dimsAndOrientation2DToMat4( m_jumppadSprite->getDimensions(), m_jumppadSprite->getOrientation() );
    m_spriteBatcher->queueSpriteInstance( m_jumppadSprite->getHandle(), mod );
}

void Marshmellow::queueJumpPadSprite()
{
   glm::mat4 model;
   for ( int i = 0; i < JumpPadBuffer.size(); i++){
       SimpleSprite2D pad = JumpPadBuffer[i];
       if (pad.getOrientation().position.y < (m_camera.getPosition().y-3.5)){
           auto m = m_jumppadSprite->getOrientation();
           m.position.x = ((1+rand())/(RAND_MAX / (20 - 1 + 1) + 1)) - 10;
           m.position.y = pad.getOrientation().position.y+7;
           for (int j = 0; j < i; j++){
               if (colliding(pad, JumpPadBuffer[j])){
                   auto n = m_jumppadSprite->getOrientation();
                   n.position.x = ((1+rand())/(RAND_MAX / (20 - 1 + 1) + 1)) - 10;
                   n.position.y = pad.getOrientation().position.y+7;
                   JumpPadBuffer[j].setOrientation(n);
               }
           }
           JumpPadBuffer[i].setOrientation(m);
       }
       model = dimsAndOrientation2DToMat4( pad.getDimensions(), pad.getOrientation() );
       m_spriteBatcher->queueSpriteInstance( pad.getHandle(), model );
   }

}

void Marshmellow::queueSprites()
{
   m_spriteBatcher->clearInstances();
   queueBackgroundSprite();
   queueDoodlerSprite();
   queueJumpPadSprite();
   //queueInitialJumpPadSprite();
   //queueMovingPad();
   // TODO: Queue more sprites to draw here
}

void Marshmellow::queueDoodlerSprite()
{
   // A MultiSprite provides a list of sprites to draw at any one time
   // Draw each one of them independently
   // Consider making a MultiSprite batching function to generalize this one
   Doodler doodle;
   std::vector<SimpleSprite2D> doodlerSprites = m_doodlerSprite->getSpritesToDraw();
   for( int i = 0; i < doodlerSprites.size(); i++ )
   {
       SimpleSprite2D sprite = doodlerSprites[ i ];
       glm::mat4 model = dimsAndOrientation2DToMat4( sprite.getDimensions(), sprite.getOrientation() );
       m_spriteBatcher->queueSpriteInstance( sprite.getHandle(), model );
   }
}
void Marshmellow::queueMovingPad(){
    auto o = m_jumpMoveSprite->getOrientation();
    m_jumpMoveSprite->setOrientation(o);
    glm::mat4 mod = dimsAndOrientation2DToMat4( m_jumpMoveSprite->getDimensions(), m_jumpMoveSprite->getOrientation() );
    m_spriteBatcher->queueSpriteInstance( m_jumpMoveSprite->getHandle(), mod );
}

void Marshmellow::generatejumppad(){
   auto m = m_jumppadSprite->getOrientation();
   for (int i=0;i<7;i++){
       m.position.x= ((1+rand())/(RAND_MAX / (20 - 1 + 1) + 1)) - 10;
       m.position.y= -0.5;
       m_jumppadSprite->setOrientation(m);
       JumpPadBuffer.push_back(*m_jumppadSprite);
   }
}

// ----------------------------------------------------------------
// Graphics - Do not modify below this line
// ----------------------------------------------------------------

void Marshmellow::initializeGraphics()
{
   m_graphicsObject = std::make_unique<GraphicsObject>();
   m_graphicsObject->printGLVersionInfo();
   m_spriteBatcher = std::make_unique<SpriteBatcher>();
   loadGraphicsAssets();
}

void Marshmellow::loadGraphicsAssets()
{
   loadShaders();
   loadSprites();
}

void Marshmellow::loadShaders()
{
   ShaderFileRepository repo;
   std::ifstream vertFile( "shaders/sprite2d/sprite2d.vert" );
   std::ifstream fragFile( "shaders/sprite2d/sprite2d.frag" );
   repo.loadVertexShader( vertFile );
   repo.loadFragmentShader( fragFile );
   ShaderSourceData ssd = repo.getShaderSourceData()[0];
   m_shader = std::make_unique<Shader>( ssd.vertexSource, ssd.fragmentSource );
}

int Marshmellow::texPathToSpriteHandle( const std::string &path )
{
   TextureParams p;
   Tex2D tex = m_textureLoader->loadTex2D( path, p );
   int texHandle = m_textureCache.storeTexture( std::move( tex ) );
   return m_spriteBatcher->registerSprite( m_textureCache.getTexture( texHandle ) );
}

MultiSpriteData Marshmellow::multiSpriteFileDataToMultiSpriteData( const MultiSpriteFileData& fdata )
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

SimpleSprite2DData Marshmellow::spriteFileDataToSpriteData( const SimpleSprite2DFileData& d)
{
   SimpleSprite2DData data;
   data.dimensions = d.dimensions;
   data.offset = d.offset;
   data.handle = texPathToSpriteHandle( d.path );
   return data;
}

void Marshmellow::clearScreen()
{
   m_graphicsObject->enableDepth();
   m_graphicsObject->setClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
   m_graphicsObject->clearColorBuffer();
   m_graphicsObject->clearDepthBuffer();
}

void Marshmellow::setBlendState()
{
   m_graphicsObject->enableBlend();
   m_graphicsObject->setBlendMode( GraphicsObject::BLEND_MODE::SRC_ALPHA, GraphicsObject::BLEND_MODE::ONE_MINUS_SRC_ALPHA );
}

void Marshmellow::drawSprites()
{
   //
   m_shader->bind();
   setBlendState();
   m_shader->applyUniform( ShaderVar( m_camera.getViewMatrix(), "viewMatrix" ) );
   m_shader->applyUniform( ShaderVar( m_camera.getProjectionMatrix(), "projectionMatrix" ) );

   m_spriteBatcher->drawSprites( m_shader.get(), "modelMatrix", "texMap" );

   m_shader->unbind();
}

void Marshmellow::resize( Rect2D<int> dims )
{
   glViewport( 0, 0, dims.width, dims.height );

   float ratio = static_cast<float>( dims.height ) / static_cast<float>( dims.width );
   m_camera.setHeight( ratio*m_gameWidth );
   m_camera.setWidth( m_gameWidth );
}
