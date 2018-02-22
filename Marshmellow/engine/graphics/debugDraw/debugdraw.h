#ifndef DEBUGDRAW_H
#define DEBUGDRAW_H

#include "glm/glm.hpp"

class Shader;

class DebugDraw
{
public:
    DebugDraw();

    void drawAll();
    void initGL();

    // Add other shapes to procrastinate
//    void cylinder( glm::vec3 pos, float scale );
//    void lineCylinder( glm::vec3 pos, float scale );
//    void lineSphere( glm::vec3 pos, float scale );
//    void sphere( glm::vec3 pos, float r );

private:

    Shader* m_debugShader;

    glm::vec3 m_color;

};

#endif // DEBUGDRAW_H
