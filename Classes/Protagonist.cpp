#include "Protagonist.h"

bool Protagonist::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}