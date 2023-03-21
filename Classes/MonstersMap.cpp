#include "MonstersMap.h"

bool MonstersMap::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}