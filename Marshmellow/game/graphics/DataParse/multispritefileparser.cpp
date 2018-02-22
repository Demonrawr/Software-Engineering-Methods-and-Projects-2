#include "multispritefileparser.h"

#include "tinyxml2.h"

#include "game/graphics/DataParse/simplesprite2dfileparser.h"
#include "game/graphics/DataParse/multispritefiledata.h"

MultiSpriteFileData pathToMultiSpriteFileData( const std::string& path )
{
    using namespace tinyxml2;
    XMLDocument doc;
    doc.LoadFile( path.c_str() );
    return nodeToMultiSpriteFileData( doc.FirstChildElement("MultiSprite") );
}

MultiSpriteStateFileData nodeToMultiSpriteStateFileData( tinyxml2::XMLNode* node )
{
    using namespace tinyxml2;

    MultiSpriteStateFileData stateData;

    XMLElement *spriteNode = node->FirstChildElement( "Sprite" );
    while( spriteNode )
    {
        std::string spriteName = spriteNode->Attribute( "name" );
        stateData.sprites[spriteName] = nodeToSimpleSprite2DFileData( spriteNode );
        spriteNode = spriteNode->NextSiblingElement();
    }

    return stateData;
}

MultiSpriteFileData nodeToMultiSpriteFileData( tinyxml2::XMLNode* node )
{
    using namespace tinyxml2;

    MultiSpriteFileData data;

    XMLElement* stateNode = node->FirstChildElement( "State" );

    while( stateNode )
    {
        MultiSpriteStateFileData state  = nodeToMultiSpriteStateFileData( stateNode );
        std::string stateName = stateNode->Attribute("name" );
        data.states[ stateName ] = state;

        stateNode = stateNode->NextSiblingElement();
    }

    return data;
}
