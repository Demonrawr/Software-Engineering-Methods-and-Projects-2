#ifndef MULTISPRITEFILEDATA
#define MULTISPRITEFILEDATA

#include <map>
#include <string>

#include "engine/graphics/sprite2d/simplesprite2dfiledata.h"

struct MultiSpriteStateFileData
{
    std::map<std::string, SimpleSprite2DFileData> sprites;
};

struct MultiSpriteFileData
{
    std::map<std::string, MultiSpriteStateFileData> states;
};

#endif // MULTISPRITEFILEDATA

