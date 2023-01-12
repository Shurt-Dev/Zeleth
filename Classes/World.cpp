#include "World.h"

bool World::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}