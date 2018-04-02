#ifndef INPUTSELECTOR_H
#define INPUTSELECTOR_H

#include <vector>

#include "engine/input/inputmacros.h"

class InputSelector
{
public:
    InputSelector();

    void pressKey( KEYBOARD_KEY );
    void releaseKey( KEYBOARD_KEY );
    void pressMouseButton( MOUSE_BUTTON );
    void releaseMouseButton( MOUSE_BUTTON );

    std::vector<KEYBOARD_KEY> getPressedKeys();
    std::vector<KEYBOARD_KEY> getReleasedKeys();

    std::vector<MOUSE_BUTTON> getPressedMouseButtons();
    std::vector<MOUSE_BUTTON> getReleasedMouseButtons();

private:
    std::vector<KEYBOARD_KEY> m_pressedKeys;
    std::vector<KEYBOARD_KEY> m_releasedKeys;

    std::vector<MOUSE_BUTTON> m_pressedMouseButtons;
    std::vector<MOUSE_BUTTON> m_releasedMouseButtons;

};

#endif // INPUTSELECTOR_H
