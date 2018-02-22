#version 400

uniform vec2 iResolution;
uniform float time;

uniform float percent;

out vec4 fragColor;


void main(void)
{
	vec2 uv = gl_FragCoord.xy / iResolution.xy;//*2.0-1.0;
	
    float hurp = smoothstep( 0, percent, 2.0*percent - uv.y );//uv.y, percent );
    hurp *= hurp * hurp * hurp;
    hurp *= hurp * hurp;
    float durp = smoothstep( 1, 0, abs( uv.x*2-1 )*0.5 );
    float y = abs( uv.y * 2 - 1 );

    durp *= durp * durp * durp;
    durp *= durp * durp;
	fragColor = vec4( vec3( 1, 0, 0 ) * hurp * durp, hurp * durp );
}