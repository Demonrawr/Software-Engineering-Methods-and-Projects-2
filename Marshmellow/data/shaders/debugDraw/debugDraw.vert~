#version 400

// Inputs

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_texCoord;


// Uniforms 

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


// Vars
mat4 MVPMatrix = modelMatrix * viewMatrix * projectionMatrix;

// Outs
out vec3 f_position;
out vec3 f_normal;
out vec2 f_texCoord;

void main ()
{
	mat4 MVPMatrix = projectionMatrix * viewMatrix * modelMatrix;
	
	f_position = (modelMatrix * vec4( in_position, 1 ) ).xyz;
	f_normal = normalize((inverse(transpose(modelMatrix*viewMatrix))*vec4(in_normal,0)).xyz);
	f_texCoord = in_texCoord;

	gl_Position = MVPMatrix * vec4(in_position,1);
}
