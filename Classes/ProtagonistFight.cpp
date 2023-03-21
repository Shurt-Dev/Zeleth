#include "ProtagonistFight.h"

bool ProtagonistFight::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    life = 180.0f;
    damage = 20.0f;
    initiative = 80.0f;
    name = "Oskar Khas";

    return true;
}