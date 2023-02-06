#include "World.h"

bool World::init()
{
    if (!Node::init())
    {
        return false;
    }

    createEuphoriaTileMap();
    createProtagonist();
    createCamera();

    return true;
}

void World::createEuphoriaTileMap()
{
    // Euphoria Map
    tileMap.loadEuphoriaTileMap();

    this->addChild(tileMap.getEuphoriaMap());
}

void World::createProtagonist()
{
    // Create Protagonist
    entities.createProtagonist();

    // set protagonist spawn
    tileMap.setSpawnProtagonist();
        
    this->addChild(entities.setProtagonist());
}

void World::createCamera()
{
    m_follow = Follow::create(entities.setProtagonist());

    this->runAction(m_follow);
}