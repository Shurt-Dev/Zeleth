#include "Attack.h"

bool Attack::init()
{
    if (!Node::init())
    {
        return false;
    }

    createAttackZone();

    return true;
}

void Attack::createAttackZone()
{
    m_attackZone = Sprite::create("sprites/background/attack_zone.png");

    this->addChild(m_attackZone);
}

Sprite* Attack::getAttackZone()
{
    return m_attackZone;
}