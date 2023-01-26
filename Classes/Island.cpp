#include "Island.h"

bool Island::init()
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

void Island::createEuphoriaTileMap()
{
    // Euphoria Map
    tileMap.loadEuphoriaTileMap();

    this->addChild(tileMap.getEuphoriaMap());
}

void Island::createProtagonist()
{
    // Create Protagonist
    entities.createProtagonist();

    this->addChild(entities.setProtagonist());
}

void Island::createCamera()
{
    m_follow = Follow::create(entities.setProtagonist());

    this->runAction(m_follow);
}