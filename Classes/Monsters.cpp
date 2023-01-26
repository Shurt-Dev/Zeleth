#include "Monsters.h"

bool Monsters::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}