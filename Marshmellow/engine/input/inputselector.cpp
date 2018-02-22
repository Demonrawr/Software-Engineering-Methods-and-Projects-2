#include "engine/input/inputselector.h"

InputSelector::InputSelector()
{

}

void InputSelector::pressKey( KEYBOARD_KEY key )
{
    m_pressedKeys.push_back( key );
}

void InputSelector::releaseKey( KEYBOARD_KEY key )
{
    m_releasedKeys.push_back( key );
}

void InputSelector::pressMouseButton( MOUSE_BUTTON button )
{
    m_pressedMouseButtons.push_back( button );
}

void InputSelector::releaseMouseButton( MOUSE_BUTTON button )
{
    m_releasedMouseButtons.push_back( button );
}

std::vector<KEYBOARD_KEY> InputSelector::getPressedKeys()
{
    std::vector<KEYBOARD_KEY> ret = std::move( m_pressedKeys );
    m_pressedKeys.clear();
    return ret;
}

std::vector<KEYBOARD_KEY> InputSelector::getReleasedKeys()
{
    std::vector<KEYBOARD_KEY> ret = std::move( m_releasedKeys );
    m_releasedKeys.clear();
    return ret;
}

std::vector<MOUSE_BUTTON> InputSelector::getPressedMouseButtons()
{
    std::vector<MOUSE_BUTTON> ret = std::move( m_pressedMouseButtons );
    m_pressedMouseButtons.clear();
    return ret;
}

std::vector<MOUSE_BUTTON> InputSelector::getReleasedMouseButtons()
{
    std::vector<MOUSE_BUTTON> ret = std::move( m_releasedMouseButtons );
    m_releasedMouseButtons.clear();
    return ret;
}
