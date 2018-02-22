#ifndef ORIENTATION2D
#define ORIENTATION2D

#include "glm/glm.hpp"

struct Orientation2D
{
    Orientation2D() :
        angle( 0.0f ),
        scale( 1.0f )
    {

    }

    glm::vec2 position;
    float angle;
    float scale;
};

#endif // ORIENTATION2D
