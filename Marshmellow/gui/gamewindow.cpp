#include <GL/glew.h>
#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <memory>
#include <iostream>

#include "gui/gamerenderwidget.h"
#include "game/doodlejump.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    m_doodleJump( std::make_unique<Marshmellow>() )
{
    ui->setupUi(this);
    initGameRenderWidget();
    ui->horizontalLayout->addWidget(m_gameRenderWidget.release());

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::initGameRenderWidget()
{
    setGLFormat();

    m_gameRenderWidget = std::make_unique<GameRenderWidget>(this);
    m_gameRenderWidget->show();
    m_gameRenderWidget->registerGame( m_doodleJump.get() );

    connect(ui->startButton, SIGNAL(released()), this, SLOT(startButtonPressed()));
    connect(ui->restartButton, SIGNAL(released()), this, SLOT(restartButtonPressed()));
    connect(ui->pauseButton, SIGNAL(released()), this, SLOT(pauseButtonPressed()));
}

void GameWindow::setGLFormat()
{
    QSurfaceFormat glFormat;
    glFormat.setMajorVersion( 4 );
    glFormat.setMinorVersion( 0 );
    glFormat.setSwapBehavior(QSurfaceFormat::SwapBehavior::DoubleBuffer);
    glFormat.setProfile( QSurfaceFormat::CoreProfile );
    QSurfaceFormat::setDefaultFormat(glFormat);
}

void GameWindow::setScore(int score)
{
    ui->ScoreNumber->setText(QString::number(score));
}

void GameWindow::startButtonPressed()
{
    m_doodleJump->startButtonPressed();
}

void GameWindow::restartButtonPressed()
{
    m_doodleJump->restartButtonPressed();
}

void GameWindow::pauseButtonPressed()
{
    m_doodleJump->pauseButtonPressed();
}
