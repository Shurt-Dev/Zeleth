#include "EntitiesFight.h"

float EntitiesFight::Level()
{
    return level;
}

float EntitiesFight::Life()
{
    return life;
}

float EntitiesFight::Damage()
{
    return damage;
}

float EntitiesFight::Initiative()
{
    return initiative;
}

string EntitiesFight::Name()
{
    return name;
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