#include "Pnj.h"

bool Pnj::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}