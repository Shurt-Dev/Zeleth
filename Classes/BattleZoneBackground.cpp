#include "BattleZoneBackground.h"

bool BattleZoneBackground::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void BattleZoneBackground::createBackgroundEuphoria()
{
    m_background = Sprite::create("sprites/background/battle_zone.jpg");
}

Sprite* BattleZoneBackground::getBackgroundEuphoria()
{
    return m_background;
}