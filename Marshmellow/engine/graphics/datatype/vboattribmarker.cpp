#include "vboattribmarker.h"

VBOAttribMarker::VBOAttribMarker( Shader::ATTRIB name, GLuint n, int o, DATA_TYPE t , bool normalize ) :
    attrib( name ),
    dataType( t ),
    dataNormalize( normalize ? TRUE : FALSE ),
    numElements( n ),
    offset( o )
{

}
