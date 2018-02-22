#version 400

#define EPSILON 1e-2
#define PI 3.14152654

// Inputs
in vec3 f_positionWorld;
in vec3 f_positionCamera;
in vec3 f_normalWorld;
in vec3 f_normalCamera;
in vec2 f_texCoord;

// Uniforms
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

uniform vec3 ambientLight;
uniform vec3 dirLightColor;
uniform vec3 dirLightDir;
uniform vec3 pLightColor;
uniform vec3 pLightPos;
uniform float pLightRange;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float shininess;
uniform float alpha;
uniform sampler2D tex;

// Outs
out vec4 out_color;

void main(void)
{
// Ambient light

	vec3 ambient = ambientLight * kAmbient;

// Diffuse light
	
	vec3 n = f_normalCamera;

	// Directional diffuse
	vec3 dl = -normalize(viewMatrix*vec4(dirLightDir,0)).xyz; // point to light = - light to point
	vec3 diffuse = max(0,dot(n,dl)) * dirLightColor;

	// Point diffuse
	vec3 pl = (viewMatrix*vec4(f_positionWorld - pLightPos,0)).xyz;
	float pd2 = dot((pLightPos - f_positionWorld), (pLightPos - f_positionWorld) );
	float distAtten = pLightRange*pLightRange;
	distAtten *= distAtten;
	distAtten = max(0,1 - (pd2/distAtten));
	diffuse += distAtten * max(0,dot(n,pl)) * pLightColor;
	
	diffuse *= kDiffuse;

// Specular light
	
	// Directional specular
	vec3 r = -reflect(dl,f_normalCamera);
	vec3 v = -normalize(f_positionCamera);
	vec3 specular = pow(max(0,dot(r,v)),shininess) * dirLightColor * kSpecular;
	specular = max( vec3(0), specular );

	// Point specular
//	r = reflect(pl,f_normal);
//	specular += pow(max(0,dot(r,v)),shininess) * pLightColor * kSpecular;

	out_color = vec4( max(ambient+diffuse+specular,vec3(0.0)) , alpha);
	out_color = texture( tex, f_texCoord );
	out_color.xyz *= ambient+diffuse+specular;
}
