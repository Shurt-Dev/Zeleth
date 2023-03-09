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

bool EntitiesFight::IsEnemy()
{
    return isEnemy;
}

void EntitiesFight::takeDamage(float nbDamage)
{
    life -= nbDamage;

    if (life < 0)
    {
        life = 0;
    }
}

void EntitiesFight::attack(EntitiesFight* target)
{
    target->takeDamage(damage);
}

bool EntitiesFight::isAlive()
{
    return life > 0;
}