#ifndef DOODLEJUMP_H
#define DOODLEJUMP_H
#include <ctime>
#include <memory>
#include <string>
#include <GL/glew.h>
#include "game/entity/jumppad.h"
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

class Marshmellow
{
public:
    Marshmellow();
    ~Marshmellow();

    // Graphics
    void initializeGraphics();
    void drawFrame();
    void resize( Rect2D<int> dims );
    void setAspectRatio( float aspectRatio );
    void setCommand(PlayerCommands input){command = input;}

    // Time
    void tick( float seconds );

    // Game I/O
    void startButtonPressed();
    void restartButtonPressed();
    void pauseButtonPressed();

    int getScore() { return m_score; }

private:
    void loadGraphicsAssets();
    void loadShaders();
    void loadSprites();
    void loadDoodlerSprite();
    void loadBackgroundSprite();
    void loadJumpPad();
    void loadMovingJump();
    void resetVariables();

    int texPathToSpriteHandle( const std::string &path );

    SimpleSprite2DData spriteFileDataToSpriteData( const SimpleSprite2DFileData& d);
    MultiSpriteData multiSpriteFileDataToMultiSpriteData( const MultiSpriteFileData& fdata );

    void clearScreen();
    void setBlendState();


    void generatejumppad();

    void setCameraState();
    void queueSprites();
    void drawSprites();
    void queueBackgroundSprite();
    void queueDoodlerSprite();
    void queueJumpPadSprite();
    void queueInitialJumpPadSprite();
    void queueMovingPad();
    void doodleMovement();
    void padMovement();
    // Sprite example
    std::unique_ptr<SimpleSprite2D> m_backgroundSprite;
    SimpleSprite2DData m_backgroundSpriteData;

    //Jumppad
    std::unique_ptr<SimpleSprite2D> m_jumppadSprite;
    SimpleSprite2DData m_jumppadSpriteData;

    std::vector<SimpleSprite2D> JumpPadBuffer;

    std::unique_ptr<SimpleSprite2D> m_jumpMoveSprite;
    SimpleSprite2DData m_jumpMoveSpriteData;//Moving

    // MultiSprite example
    MultiSpriteData m_doodlerSpriteData;
    std::unique_ptr<MultiSprite> m_doodlerSprite;

    // Graphics
    Camera2D m_camera;
    std::unique_ptr<GraphicsObject> m_graphicsObject;
    std::unique_ptr<Shader> m_shader;
    std::unique_ptr<TextureLoader> m_textureLoader;
    TextureCache m_textureCache;
    std::unique_ptr<SpriteBatcher> m_spriteBatcher;

    float m_gameWidth;

    // Game State & Variables
    int m_score;
    double timer = 0;
    double initvelocity = 0;
    double velocity = 0;
    Orientation2D orientation;
    Orientation2D movepadOr;
    PlayerCommands command;
    int inverse = 1;
};

#endif // DOODLEJUMP_H
