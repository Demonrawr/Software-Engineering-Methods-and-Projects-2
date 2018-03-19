#ifndef PLAYERCOMMANDS
#define PLAYERCOMMANDS

struct PlayerCommands
{
    PlayerCommands() :
        moveLeft(false),
        moveRight( false ),
        moveUp( false ),
        shoot( false ),
        reloadSprites(false)
    {

    }

    bool moveLeft;
    bool moveRight;
    bool moveUp;
    bool shoot;
    bool reloadSprites;
};

#endif // PLAYERCOMMANDS

