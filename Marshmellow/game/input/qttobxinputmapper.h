#ifndef QTTOBXINPUTMAPPER_H
#define QTTOBXINPUTMAPPER_H

#include "engine/input/inputmacros.h"

class QtToBXInputMapper
{
public:
    enum class OS { WINDOWS, MAC };
    QtToBXInputMapper();
    QtToBXInputMapper( OS os );

    KEYBOARD_KEY key( int key );
    MOUSE_BUTTON mouseButton( int mouseButton );

private:
    OS m_os;
};

#endif // QTTOBXINPUTMAPPER_H
