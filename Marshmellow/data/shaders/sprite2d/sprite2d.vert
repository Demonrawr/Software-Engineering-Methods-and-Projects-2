#version 400

layout (location = 0) in vec2 in_position;
layout (location = 2) in vec2 in_texCoord;

out vec2 thru_texCoords;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
    thru_texCoords = in_texCoord;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_position, 0.0, 1.0);
}