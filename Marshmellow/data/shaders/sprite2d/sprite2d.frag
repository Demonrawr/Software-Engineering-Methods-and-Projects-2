#version 400

in vec2 thru_texCoords;

out vec4 color;

uniform sampler2D texMap;

void main()
{    
    color = texture(texMap, thru_texCoords);
    if( color.a == 0.0f )
    	discard;
}