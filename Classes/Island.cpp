#include "Island.h"

bool Island::init()
{
    if (!Node::init())
    {
        return false;
    }

    createEuphoriaTileMap();
    createProtagonist();

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