#include "TileMap.h"

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void TileMap::loadEuphoriaTileMap()
{
    // Chargement de la carte à tuiles à partir d'un fichier .tmx
    m_euphoriaTileMap = TMXTiledMap::create("tiled/map.tmx");
    // resize x4
    m_euphoriaTileMap->setScale(4.0f);
}

TMXTiledMap* TileMap::getEuphoriaMap()
{
    return m_euphoriaTileMap;
}