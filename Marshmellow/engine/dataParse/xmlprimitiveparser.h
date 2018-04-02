#ifndef XMLPRIMITIVEPARSER_H
#define XMLPRIMITIVEPARSER_H

#include "glm/glm.hpp"

namespace tinyxml2
{
    class XMLElement;
}

namespace XMLPrimitiveParser
{
    float parseFloat( tinyxml2::XMLElement *e );
    glm::vec2 parseVec2( tinyxml2::XMLElement *e );
    glm::vec3 parseVec3( tinyxml2::XMLElement *e );
    glm::vec4 parseVec4( tinyxml2::XMLElement *e );
}

#endif // XMLPRIMITIVEPARSER_H
