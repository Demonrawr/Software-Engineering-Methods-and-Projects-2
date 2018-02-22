#ifndef MULTISPRITEFILEPARSER_H
#define MULTISPRITEFILEPARSER_H

#include <string>

namespace tinyxml2
{
    class XMLNode;
}

struct MultiSpriteFileData;


MultiSpriteFileData pathToMultiSpriteFileData( const std::string& path );

MultiSpriteFileData nodeToMultiSpriteFileData( tinyxml2::XMLNode* node );

#endif // MULTISPRITEFILEPARSER_H
