#include "textureparams.h"

TextureParams::TextureParams( COLOR_FORMAT c, FILTER_METHOD f, WRAP_METHOD w ) :
    colorFormat( c ),
    filterMethod( f ),
    wrapMethod( w )
{
}
