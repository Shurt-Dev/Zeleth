#include "EntitiesFight.h"

bool EntitiesFight::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void EntitiesFight::takeDamage(float nbDegats)
{
    life -= nbDegats;

    if (life < 0)
    {
        life = 0;
    }
}

void EntitiesFight::attack(EntitiesFight cible)
{
    cible.takeDamage(damage);
}

bool EntitiesFight::isAlive()
{
    return life > 0;
}