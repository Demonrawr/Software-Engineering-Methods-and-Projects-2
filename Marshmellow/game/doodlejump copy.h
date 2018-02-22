#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H

#include <memory>
#include <string>
#include <GL/glew.h>

#include "engine/input/inputselector.h"
#include "engine/graphics/camera/camera2d.h"
#include "engine/graphics/texture/texturecache.h"
#include "engine/graphics/util/util.h"
#include "engine/physics/orientation2d.h"
#include "game/entity/doodler.h"
#include "game/entity/jumppad.h"
#include "game/input/inputmapper.h"
#include "game/input/playercommands.h"
#include "engine/graphics/sprite2d/simplesprite2d.h"
#include "game/graphics/multisprite/multisprite.h"

class GraphicsObject;
class Shader;
class SpriteBatcher;
class TextureLoader;

struct SimpleSprite2DFileData;
struct MultiSpriteFileData;

#include "tinyxml2.h"

class DoodleJump
{
public:
    DoodleJump();
    ~DoodleJump();

    // Inputs
//    InputSelector& getInputSelector();

    // Graphics
    void initializeGraphics();
    void drawFrame();
    void resize( Rect2D<int> dims );
    void setAspectRatio( float aspectRatio );

    // Time
    void tick( float seconds );

private:
    void loadGraphicsAssets();
    void loadShaders();
    void loadSprites();
    void loadDoodlerSprite();
//    void loadJumpPadSprite();
    void loadBackgroundSprite();
//    void loadMovingJumpPadSprite();
    int texPathToSpriteHandle( const std::string &path );

    SimpleSprite2DData spriteFileDataToSpriteData( const SimpleSprite2DFileData& d);
    MultiSpriteData multiSpriteFileDataToMultiSpriteData( const MultiSpriteFileData& fdata );

//    void updateTime( float dt );
//    void processInputs();
//    void applyControls();

    void clearScreen();
    void setBlendState();

    void setCameraState();
    void queueSprites();
    void drawSprites();
    void queueBackgroundSprite();
    void queueDoodlerSprite();
//    void queueJumpPadSprites();
//    void queueMovingJumpPadSprites();

//    bool doodlerFellThroughBottom();
//    void handleDoodlerJumpPadCollisions();
//    void updateScore();
//    void updateJumpPads();
//    void refreshJumpPadSprites();

//    void updateGame();
//    void updatePageBottom();
//    glm::vec2 nextJumpPadPosition();
//    glm::vec2 lowestCurrentJumpPadPosition();

//    float m_jumpPadSpacing = 1.2f;
//    float m_lastJumpPadHeight = - 3.0f * m_jumpPadSpacing;
//    int m_numJumpPads = 15;


//    enum GAME_STATE { START, PLAY, GAME_OVER };

//    float m_oldTime;
//    float m_time;
//    float m_dt;

//    GAME_STATE m_gameState;

//    std::vector<SimpleSprite2D> m_jumpPads;
//    int m_jumpPadSpriteHandle;
//    SimpleSprite2DData m_jumpPadSpriteData;

    std::unique_ptr<SimpleSprite2D> m_backgroundSprite;
    SimpleSprite2DData m_backgroundSpriteData;

    MultiSpriteData m_doodlerSpriteData;
    std::unique_ptr<MultiSprite> m_doodlerSprite;

//    float m_pageBottom;

//    InputMapper m_inputMapper;
//    PlayerCommands m_playerCommands;
//    float m_moveSpeed;
    Camera2D m_camera;
//    InputSelector m_inputSelector;

    // Graphics
    std::unique_ptr<GraphicsObject> m_graphicsObject;
    std::unique_ptr<Shader> m_shader;
    std::unique_ptr<TextureLoader> m_textureLoader;
    TextureCache m_textureCache;
    std::unique_ptr<SpriteBatcher> m_spriteBatcher;
};

#endif // DOODLEJUMP_H
