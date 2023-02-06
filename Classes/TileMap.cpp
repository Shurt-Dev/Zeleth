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

    setObjects();
}

TMXTiledMap* TileMap::getEuphoriaMap()
{
    return m_euphoriaTileMap;
}

void TileMap::setObjects()
{
    // Obtain the object group named "Objects"
    m_objectGroup = m_euphoriaTileMap->getObjectGroup("Objects");
}

void TileMap::setSpawnProtagonist()
{
    // Obtain the object named "SpawnPoint" from the object group
    spawnProtagonist = m_objectGroup->getObject("SpawnProtagonist");

    // Retrieve the x and y coordinates of the SpawnPoint object
    int x = spawnProtagonist["x"].asInt();
    int y = spawnProtagonist["y"].asInt();

    // Calculate the distance that the tile map needs to be moved to center the SpawnPoint object
    visibleSize = Director::getInstance()->getVisibleSize();

    float xMovement = visibleSize.width / 2 - x * 4;
    float yMovement = visibleSize.height / 2 - y * 4;

    // Move the tile map by the necessary distance
    m_euphoriaTileMap->setPosition(m_euphoriaTileMap->getPosition() + Vec2(xMovement, yMovement));
}