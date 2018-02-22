#ifndef TEXTUREPARAMS_H
#define TEXTUREPARAMS_H

#include "GL/glew.h"

struct TextureParams
{   
    enum COLOR_FORMAT { FORMAT_ALPHA = GL_ALPHA,
                        FORMAT_LUMINANCE = GL_LUMINANCE,
                        FORMAT_LUMINANCE_ALPHA = GL_LUMINANCE_ALPHA,
                        FORMAT_RGB = GL_RGB,
                        FORMAT_RGBA = GL_RGBA   };

    enum FILTER_METHOD { FILTER_NEAREST = GL_NEAREST,
                        FILTER_LINEAR = GL_LINEAR   };

    enum WRAP_METHOD { WRAP_CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
                       WRAP_REPEAT = GL_REPEAT };

    TextureParams( COLOR_FORMAT c = FORMAT_RGBA, FILTER_METHOD f = FILTER_LINEAR, WRAP_METHOD w = WRAP_CLAMP_TO_EDGE );

    COLOR_FORMAT colorFormat;
    FILTER_METHOD filterMethod;
    WRAP_METHOD wrapMethod;

};

#endif // TEXTUREPARAMS_H
