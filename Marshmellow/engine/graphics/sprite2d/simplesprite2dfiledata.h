#ifndef SIMPLESPRITE2DFILEDATA
#define SIMPLESPRITE2DFILEDATA

#include <string>

#include "glm/glm.hpp"

struct SimpleSprite2DFileData
{
    glm::vec2 dimensions;
    glm::vec2 offset;
    std::string path;
};

#endif // SIMPLESPRITE2DFILEDATA

