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
    actions = Sprite::create("sprites/background/actions.jpg");
}

Sprite* Actions::getActions()
{
    return actions;
}