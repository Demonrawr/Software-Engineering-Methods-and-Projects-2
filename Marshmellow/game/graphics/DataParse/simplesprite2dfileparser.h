#ifndef SIMPLESPRITE2DFILEPARSER_H
#define SIMPLESPRITE2DFILEPARSER_H

#include <string>

struct SimpleSprite2DFileData;

namespace tinyxml2
{
    class XMLNode;
}

SimpleSprite2DFileData pathToSimpleSprite2DFileData( const std::string& path );

SimpleSprite2DFileData nodeToSimpleSprite2DFileData( tinyxml2::XMLNode* node );


#endif // SIMPLESPRITE2DFILEPARSER_H
