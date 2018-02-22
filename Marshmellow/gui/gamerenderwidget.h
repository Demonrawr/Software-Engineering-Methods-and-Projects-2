#ifndef GAMERENDERWIDGET_H
#define GAMERENDERWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include "game/input/inputmapper.h"
#include "game/input/qttobxinputmapper.h"
#include "engine/input/inputselector.h"
class QtToBXInputMapper;

class Marshmellow;

namespace Ui {
class GameRenderWidget;
}

class GameRenderWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit GameRenderWidget(QWidget *parent = 0);
    ~GameRenderWidget();

    void registerGame( Marshmellow* );

protected:
    virtual void mousePressEvent( QMouseEvent* ) override;
    virtual void mouseMoveEvent( QMouseEvent* ) override;
    virtual void mouseReleaseEvent( QMouseEvent* ) override;

    virtual void keyPressEvent( QKeyEvent* ) override;
    virtual void keyReleaseEvent( QKeyEvent* ) override;

    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

private:
    Ui::GameRenderWidget *ui;

    QTimer m_timer;
    Marshmellow *m_doodleJump;

    void osSpecificSetup();
    void setupMac();
    void setupWindows();
    void timerSetup();

    QtToBXInputMapper qbim;
    InputSelector selector;
    InputMapper mapper;
    PlayerCommands tempPC;
};

#endif // GAMERENDERWIDGET_H
