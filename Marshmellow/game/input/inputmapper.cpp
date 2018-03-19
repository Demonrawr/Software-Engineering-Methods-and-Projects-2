#include "inputmapper.h"
#include <QDebug>
#include <vector>
#include <iostream>
#include "engine/input/inputmacros.h"
#include "engine/input/inputselector.h"
#include "game/input/playercommands.h"

InputMapper::InputMapper()
{

}

PlayerCommands InputMapper::keysToCommands( InputSelector &inputSelector )
{
    PlayerCommands playerCommands = m_previousCommands;
    processPressedKeys( inputSelector, playerCommands );
    processReleasedKeys( inputSelector, playerCommands );
    m_previousCommands = playerCommands;
    return playerCommands;
}

void InputMapper::processPressedKeys( InputSelector &inputSelector, PlayerCommands &playerCommands )
{
    std::vector<KEYBOARD_KEY> pressedKeys = inputSelector.getPressedKeys();
    playerCommands.shoot = false;
    for( int i = 0; i < pressedKeys.size(); i++ )
    {
        switch( pressedKeys[ i ] )
        {
        case KEYBOARD_KEY::KEY_A:
        case KEYBOARD_KEY::KEY_LEFT_ARROW:
            playerCommands.moveLeft = true;
        break;
        case KEYBOARD_KEY::KEY_D:
        case KEYBOARD_KEY::KEY_RIGHT_ARROW:
            playerCommands.moveRight = true;
        break;
        case KEYBOARD_KEY::KEY_SPACE:
            playerCommands.shoot = true;
            break;
        case KEYBOARD_KEY::KEY_W:
        case KEYBOARD_KEY::KEY_UP_ARROW:
            playerCommands.moveUp = true;
            break;
        break;
        }
    }
}



void InputMapper::processReleasedKeys( InputSelector &inputSelector, PlayerCommands &playerCommands )
{
    std::vector<KEYBOARD_KEY> releasedKeys = inputSelector.getReleasedKeys();
    playerCommands.reloadSprites = false;
    for( int i = 0; i < releasedKeys.size(); i++ )
    {
        switch( releasedKeys[ i ] )
        {
        case KEYBOARD_KEY::KEY_A:
        case KEYBOARD_KEY::KEY_LEFT_ARROW:
            playerCommands.moveLeft = false;
        break;
        case KEYBOARD_KEY::KEY_D:
        case KEYBOARD_KEY::KEY_RIGHT_ARROW:
            playerCommands.moveRight = false;
            break;
        case KEYBOARD_KEY::KEY_W:
        case KEYBOARD_KEY::KEY_UP_ARROW:
            playerCommands.moveUp = false;
            break;
        case KEYBOARD_KEY::KEY_R:
            playerCommands.reloadSprites = true;
        break;
        }
    }
}
