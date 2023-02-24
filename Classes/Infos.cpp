#include "Infos.h"

bool Infos::init()
{
    if (!Node::init())
    {
        return false;
    }

    createInfosZone();

    return true;
}

void Infos::createInfosZone()
{
    m_infosZone = Sprite::create("sprites/background/infos_zone.png");

    this->addChild(m_infosZone);
}

Sprite* Infos::getInfosZone()
{
    return m_infosZone;
}