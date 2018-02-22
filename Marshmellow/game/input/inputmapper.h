#ifndef INPUTMAPPER_H
#define INPUTMAPPER_H

class InputSelector;
//struct PlayerCommands;


#include "game/input/playercommands.h"

class InputMapper
{
public:
    InputMapper();

    PlayerCommands keysToCommands( InputSelector &inputSelector );

private:
    void processPressedKeys( InputSelector &inputSelector, PlayerCommands &playerCommands );
    void processReleasedKeys( InputSelector &inputSelector, PlayerCommands &playerCommands );

    PlayerCommands m_previousCommands;
};

#endif // INPUTMAPPER_H
