#include "EntitiesMap.h"

bool EntitiesMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void EntitiesMap::createProtagonist()
{
    m_protagonist = ProtagonistMap::create();
}

ProtagonistMap* EntitiesMap::setProtagonist()
{
    return m_protagonist;
}