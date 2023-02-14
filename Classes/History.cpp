#include "History.h"

bool History::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void History::createHistory()
{
    history = Sprite::create("sprites/background/history.png");
}

Sprite* History::getHistory()
{
    return history;
}