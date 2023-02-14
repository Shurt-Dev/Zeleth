#include "Actions.h"

bool Actions::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void Actions::createActions()
{
    actions = Sprite::create("sprites/background/attack_zone.png");
}

Sprite* Actions::getActions()
{
    return actions;
}