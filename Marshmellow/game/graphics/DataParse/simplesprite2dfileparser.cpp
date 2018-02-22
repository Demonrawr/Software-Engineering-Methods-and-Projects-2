#include "simplesprite2dfileparser.h"

#include <iostream>

#include "engine/graphics/sprite2d/simplesprite2dfiledata.h"
#include "engine/dataParse/xmlprimitiveparser.h"

#include "tinyxml2.h"

SimpleSprite2DFileData pathToSimpleSprite2DFileData( const std::string& path )
{
    using namespace tinyxml2;
    XMLDocument doc;
    doc.LoadFile(path.c_str());
    return nodeToSimpleSprite2DFileData(doc.FirstChild());
}

SimpleSprite2DFileData nodeToSimpleSprite2DFileData(tinyxml2::XMLNode *node)
{
    using namespace tinyxml2;
    SimpleSprite2DFileData d;
    XMLElement* dimsNode = node->FirstChildElement( "Dimensions" );

    if( dimsNode )
    {
        d.dimensions = XMLPrimitiveParser::parseVec2( dimsNode );
    }
    else
    {
        std::cout << "Warning: No dimensions specified for sprite" << std::endl;
    }

    std::string path( node->FirstChildElement( "TexturePath" )->GetText() );
    d.path = path;

    XMLElement* offsetNode = node->FirstChildElement( "Offset" );
    if( offsetNode )
    {
        d.offset = XMLPrimitiveParser::parseVec2( offsetNode );
    }

    return d;
}
