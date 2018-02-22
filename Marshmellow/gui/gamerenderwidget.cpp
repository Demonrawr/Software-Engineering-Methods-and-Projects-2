#include "GL/glew.h"

#include "gamerenderwidget.h"
#include "ui_gamerenderwidget.h"

#include <QKeyEvent>
#include <QGLFormat>

#include "gamewindow.h"
#include "game/doodlejump.h"

GameRenderWidget::GameRenderWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::GameRenderWidget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    timerSetup();
}

GameRenderWidget::~GameRenderWidget()
{
    delete ui;
}

void GameRenderWidget::registerGame(Marshmellow *doodleJump)
{
    m_doodleJump = doodleJump;
}


void GameRenderWidget::mousePressEvent( QMouseEvent* event )
{
    // TODO
    // Convert Qt Mouse Events to Marshmellow-specific mouse events
    // You will need to come up with your own mouse events
    // The important information is whether the mouse was pressed,
    //      released, or dragged, as well as its 2D click position
    //
}

void GameRenderWidget::mouseMoveEvent( QMouseEvent* )
{
    // TODO
}

void GameRenderWidget::mouseReleaseEvent( QMouseEvent* event )
{
    // TODO
}

void GameRenderWidget::keyPressEvent( QKeyEvent* key )
{
    // TODO
    // Convert Qt Keys to Marshmellow-specific keys
    // You will need to come up with your own key enums
    // The important information is whether the key was
    //      pressed or released, as well as which key it
    //      was.
    selector.pressKey(qbim.key(key->key()));
    tempPC = mapper.keysToCommands(selector);
    m_doodleJump->setCommand(tempPC);
}

void GameRenderWidget::keyReleaseEvent( QKeyEvent* key )
{
    // TODO
    selector.releaseKey(qbim.key(key->key()));
    tempPC = mapper.keysToCommands(selector);
    m_doodleJump->setCommand(tempPC);
}

void GameRenderWidget::initializeGL()
{
    m_doodleJump->initializeGraphics();
}

void GameRenderWidget::paintGL()
{
    m_doodleJump->tick( 1.0f/60.0f );
    m_doodleJump->drawFrame();
    dynamic_cast<GameWindow*>(this->parentWidget())->setScore( m_doodleJump->getScore());
}

void GameRenderWidget::timerSetup()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));

    if(format().swapInterval() == -1)
    {
        // VSync unavailable
        fprintf( stderr, "Swap Buffers at v_blank not available: refresh at approx 60fps.\n" );
        m_timer.setInterval(10);
    }
    else
    {
        // VSync available
        m_timer.setInterval(0);
    }
    m_timer.start();
}

void GameRenderWidget::resizeGL(int w, int h)
{
    m_doodleJump->resize( Rect2D<int>{w,h} );
}

