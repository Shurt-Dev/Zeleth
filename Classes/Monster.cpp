#include "Monster.h"

bool Monster::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}