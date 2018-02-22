#include "qttobxinputmapper.h"
#include <iostream>
#include <QKeyEvent>
#include <QDebug>
QtToBXInputMapper::QtToBXInputMapper()
{

}

QtToBXInputMapper::QtToBXInputMapper(OS os) :
    m_os( os )
{

}

KEYBOARD_KEY QtToBXInputMapper::key( int key )
{
    switch( key )
    {
    case Qt::Key_A:
        return KEYBOARD_KEY::KEY_A;
        break;
    case Qt::Key_B:
        return KEYBOARD_KEY::KEY_B;
        break;
    case Qt::Key_C:
        return KEYBOARD_KEY::KEY_C;
        break;
    case Qt::Key_D:
        return KEYBOARD_KEY::KEY_D;
        break;
    case Qt::Key_E:
        return KEYBOARD_KEY::KEY_E;
        break;
    case Qt::Key_F:
        return KEYBOARD_KEY::KEY_F;
        break;
    case Qt::Key_G:
        return KEYBOARD_KEY::KEY_G;
        break;
    case Qt::Key_H:
        return KEYBOARD_KEY::KEY_H;
        break;
    case Qt::Key_I:
        return KEYBOARD_KEY::KEY_I;
        break;
    case Qt::Key_J:
        return KEYBOARD_KEY::KEY_J;
        break;
    case Qt::Key_K:
        return KEYBOARD_KEY::KEY_K;
        break;
    case Qt::Key_L:
        return KEYBOARD_KEY::KEY_L;
        break;
    case Qt::Key_M:
        return KEYBOARD_KEY::KEY_M;
        break;
    case Qt::Key_N:
        return KEYBOARD_KEY::KEY_N;
        break;
    case Qt::Key_O:
        return KEYBOARD_KEY::KEY_O;
        break;
    case Qt::Key_P:
        return KEYBOARD_KEY::KEY_P;
        break;
    case Qt::Key_Q:
        return KEYBOARD_KEY::KEY_Q;
        break;
    case Qt::Key_R:
        return KEYBOARD_KEY::KEY_R;
        break;
    case Qt::Key_S:
        return KEYBOARD_KEY::KEY_S;
        break;
    case Qt::Key_T:
        return KEYBOARD_KEY::KEY_T;
        break;
    case Qt::Key_U:
        return KEYBOARD_KEY::KEY_U;
        break;
    case Qt::Key_V:
        return KEYBOARD_KEY::KEY_V;
        break;
    case Qt::Key_W:
        return KEYBOARD_KEY::KEY_W;
        break;
    case Qt::Key_X:
        return KEYBOARD_KEY::KEY_X;
        break;
    case Qt::Key_Y:
        return KEYBOARD_KEY::KEY_Y;
        break;
    case Qt::Key_Z:
        return KEYBOARD_KEY::KEY_Z;
        break;

    case Qt::Key_0:
        return KEYBOARD_KEY::KEY_NUM_ROW_0;
        break;
    case Qt::Key_1:
        return KEYBOARD_KEY::KEY_NUM_ROW_1;
        break;
    case Qt::Key_2:
        return KEYBOARD_KEY::KEY_NUM_ROW_2;
        break;
    case Qt::Key_3:
        return KEYBOARD_KEY::KEY_NUM_ROW_3;
        break;
    case Qt::Key_4:
        return KEYBOARD_KEY::KEY_NUM_ROW_4;
        break;
    case Qt::Key_5:
        return KEYBOARD_KEY::KEY_NUM_ROW_5;
        break;
    case Qt::Key_6:
        return KEYBOARD_KEY::KEY_NUM_ROW_6;
        break;
    case Qt::Key_7:
        return KEYBOARD_KEY::KEY_NUM_ROW_7;
        break;
    case Qt::Key_8:
        return KEYBOARD_KEY::KEY_NUM_ROW_8;
        break;
    case Qt::Key_9:
        return KEYBOARD_KEY::KEY_NUM_ROW_9;
        break;

    case Qt::Key_Space:
        return KEYBOARD_KEY::KEY_SPACE;
        break;
    case Qt::Key_Shift:
        return KEYBOARD_KEY::KEY_LEFT_SHIFT;
        break;
    case Qt::Key_Control:
        switch( m_os )
        {
        case OS::MAC:
            return KEYBOARD_KEY::KEY_LEFT_COMMAND;
        case OS::WINDOWS:
            return KEYBOARD_KEY::KEY_LEFT_CTRL;
        }
        break;
    case Qt::Key_Alt:
        return KEYBOARD_KEY::KEY_LEFT_ALT;
        break;
    case Qt::Key_Meta:
        switch( m_os )
        {
        case OS::MAC:
            return KEYBOARD_KEY::KEY_LEFT_CTRL;
        case OS::WINDOWS:
            return KEYBOARD_KEY::KEY_UNMAPPED;
        }
        break;
    case Qt::Key_CapsLock:
        return KEYBOARD_KEY::KEY_CAPS_LOCK;
        break;
    case Qt::Key_Tab:
        return KEYBOARD_KEY::KEY_TAB;
        break;
    case Qt::Key_Left:
        return KEYBOARD_KEY::KEY_LEFT_ARROW;
        break;
    case Qt::Key_Right:
        return KEYBOARD_KEY::KEY_RIGHT_ARROW;
        break;
    case Qt::Key_Up:
        return KEYBOARD_KEY::KEY_UP_ARROW;
        break;
    case Qt::Key_Down:
        return KEYBOARD_KEY::KEY_DOWN_ARROW;

        break;
    default:
        return KEYBOARD_KEY::KEY_UNMAPPED;
        break;
    }
}

MOUSE_BUTTON QtToBXInputMapper::mouseButton( int mouseButton )
{
    return MOUSE_BUTTON::MOUSE_LEFT;
}
