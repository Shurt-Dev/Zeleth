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
    history = Sprite::create("sprites/background/history.jpg");
}

Sprite* History::getHistory()
{
    return history;
}