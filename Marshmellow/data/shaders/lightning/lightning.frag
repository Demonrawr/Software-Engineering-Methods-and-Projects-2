#version 400

//#define RAINBOW

#define STATIC 18
#define PI 3.14159265358979323846264

uniform vec2 iResolution;
uniform float time;

// HSV2RGB code taken from http://lolengine.net/blog/2013/07/27/rgb-to-hsv-in-glsl
vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

// Rand, noise, and fbm found here on ShaderToy
float rand(vec2 n)
{ 
	return fract(sin(dot(n, vec2(17.12037, 5.71713))) * 12345.6789);
}

float noise(vec2 n)
{
	vec2 d = vec2(0.0, 1.0);
	vec2 b = floor(n), f = smoothstep(vec2(0.0), vec2(1.0), fract(n));
	return mix(mix(rand(b + d.xx), rand(b + d.yx), f.x), mix(rand(b + d.xy), rand(b + d.yy), f.x), f.y);
}

float fbm(vec2 n)
{
	float sum = 0.0, amp = 1.0;
	for (int i = 0; i < 10; i++)
    {
		sum += noise(n) * amp;
		n += n;
		amp *= 0.5;
	}
	return sum;
}

void main( void )
{
    float xtime = 2.0f * time;
    vec2 cv = vec2(-0.5,0) + gl_FragCoord.xy / iResolution.xy;
    cv.x *= iResolution.x/iResolution.y;
    vec2 uv = -1.0 + 2.0*gl_FragCoord.xy / iResolution.xy;
    uv.x *= iResolution.x/iResolution.y;
    
    float m = -gl_FragCoord.x/iResolution.x*.5+1.0;
    float thickness = 0.1;
    float d = (-2.5*thickness+2.7)*abs((0.5+m*(fbm(vec2(5.0*m-xtime*5.0-1.0))-.9))-cv.y);
    vec4 col = vec4(0.5,0.5,1.5,1);
#ifdef RAINBOW
    col = vec4(hsv2rgb(vec3(xtime*0.05+(uv.x*0.04),1,1)),1);
#endif
    float coeff = pow(max(1.042*(1.0-d),0.0),14.0) * pow(cos(cv.x*(1.2+0.19*sin(4.0*xtime))),6.0);
    gl_FragColor = col * coeff;
    //gl_FragColor.a = coeff;
}
