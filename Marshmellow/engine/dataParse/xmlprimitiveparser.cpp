#include "xmlprimitiveparser.h"

#include "tinyxml2.h"

namespace XMLPrimitiveParser
{

float parseFloat( tinyxml2::XMLElement *e )
{

    return e->GetText() ? atof( e->GetText() ) : 0;
}

glm::vec2 parseVec2( tinyxml2::XMLElement *e )
{
    using namespace tinyxml2;
    XMLElement *el = e->FirstChildElement( "X" );
    if( el )
    {
        XMLElement *y = e->FirstChildElement( "Y" );
        return glm::vec2( parseFloat( el ), parseFloat( y ) );
    }
    el = e->FirstChildElement( "R" );
    if( el )
    {
        XMLElement *g = e->FirstChildElement( "G" );
        return glm::vec2( parseFloat( el ), parseFloat( g ) );
    }
    assert( false );
    return glm::vec2( 0.0f, 0.0f );
}

glm::vec3 parseVec3( tinyxml2::XMLElement *e )
{
    using namespace tinyxml2;
    XMLElement *el = e->FirstChildElement( "X" );
    if( el )
    {
        XMLElement *y = e->FirstChildElement( "Y" );
        XMLElement *z = e->FirstChildElement( "Z" );
        return glm::vec3( parseFloat( el ), parseFloat( y ), parseFloat( z ) );
    }
    el = e->FirstChildElement( "R" );
    if( el )
    {
        XMLElement *g = e->FirstChildElement( "G" );
        XMLElement *b = e->FirstChildElement( "B" );
        return glm::vec3( parseFloat( el ), parseFloat( g ), parseFloat( b ) );
    }
    assert( false );
    return glm::vec3( 0.0f, 0.0f, 0.0f );
}

glm::vec4 parseVec4( tinyxml2::XMLElement *e )
{
    using namespace tinyxml2;
    XMLElement *el = e->FirstChildElement( "X" );
    if( el )
    {
        XMLElement *y = e->FirstChildElement( "Y" );
        XMLElement *z = e->FirstChildElement( "Z" );
        XMLElement *w = e->FirstChildElement( "W" );
        return glm::vec4( parseFloat( el ), parseFloat( y ), parseFloat( z ), parseFloat( w ) );
    }
    el = e->FirstChildElement( "R" );
    if( el )
    {
        XMLElement *g = e->FirstChildElement( "G" );
        XMLElement *b = e->FirstChildElement( "B" );
        XMLElement *a = e->FirstChildElement( "A" );
        return glm::vec4( parseFloat( el ), parseFloat( g ), parseFloat( b ), parseFloat( a ) );
    }
    assert( false );
    return glm::vec4( 0.0f, 0.0f, 0.0f, 0.0f );
}

}
