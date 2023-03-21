#include "Bag.h"

bool Bag::init()
{
    if (!Node::init())
    {
        return false;
    }

    createBagZone();

    return true;
}

void Bag::createBagZone()
{
    m_bagZone = Sprite::create("sprites/background/bag_zone.png");

    this->addChild(m_bagZone);
}

Sprite* Bag::getBagZone()
{
    return m_bagZone;
}