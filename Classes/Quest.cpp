#include "Quest.h"

bool Quest::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}