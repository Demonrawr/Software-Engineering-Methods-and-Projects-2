#ifndef PLAYERCOMMANDS
#define PLAYERCOMMANDS

struct PlayerCommands
{
    PlayerCommands() :
        moveLeft(false),
        moveRight( false ),
        shoot( false ),
        reloadSprites(false)
    {

    }

    bool moveLeft;
    bool moveRight;
    bool shoot;
    bool reloadSprites;
};

#endif // PLAYERCOMMANDS

