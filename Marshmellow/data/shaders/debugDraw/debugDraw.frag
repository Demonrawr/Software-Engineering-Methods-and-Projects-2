#version 400

#define EPSILON 1e-2
#define PI 3.14152654

// Inputs
in vec3 f_position;
in vec3 f_normal;
in vec2 f_texCoord;

// Uniforms
uniform sampler2D tex;
uniform vec3 color = vec3(0.5,0.5,0.5);

// Outs
out vec4 out_color;

void main(void)
{
	float ambient = 0.5;
	
	vec3 n = f_normal;
	vec3 l = normalize(vec3(0,0,-1)); // It's always -1 o'clock
	
	float diffuse = max(0,dot(n,l));
	
	out_color = vec4((ambient+diffuse)*color,1);
	out_color *= texture( tex, f_texCoord );
}
