#include "Island.h"

bool Island::init()
{
    if (!Node::init())
    {
        return false;
    }

    loadMap();
    setRenderScale();
    setSpawnPointProtagonist();

    return true;
}

void Island::loadMap()
{
    // Chargement de la carte à tuiles à partir d'un fichier .tmx
    m_islandMap = TMXTiledMap::create("tiled/map.tmx");

    // ajout de la carte à tuiles à la scène
    this->addChild(m_islandMap);
}

void Island::setRenderScale()
{
    m_islandMap->setScale(4.0f);
}

void Island::setSpawnPointProtagonist()
{
    // Obtain the object group named "Objects"
    m_objectGroup = m_islandMap->getObjectGroup("Objects");

    // Obtain the object named "SpawnPoint" from the object group
    spawnPoint = m_objectGroup->getObject("StartPoint");

    // Retrieve the x and y coordinates of the SpawnPoint object
    xSpawnPoint = spawnPoint["x"].asInt();
    ySpawnPoint = spawnPoint["y"].asInt();

    // Calculate the distance that the tile map needs to be moved to center the SpawnPoint object
    visibleSize = Director::getInstance()->getVisibleSize();

    xMovement = visibleSize.width / 2 - xSpawnPoint * 4;
    yMovement = visibleSize.height / 2 - ySpawnPoint * 4;

    startPosition = Vec2(xMovement, yMovement);

    // Move the tile map by the necessary distance
    m_islandMap->setPosition(startPosition);
}