#include "Collectable.h"

bool Collectable::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}