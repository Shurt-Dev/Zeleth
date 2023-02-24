#include "Run.h"

bool Run::init()
{
    if (!Node::init())
    {
        return false;
    }

    createRunZone();

    return true;
}

void Run::createRunZone()
{
    m_runZone = Sprite::create("sprites/background/run_zone.png");

    this->addChild(m_runZone);
}

Sprite* Run::getRunZone()
{
    return m_runZone;
}