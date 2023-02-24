#include "History.h"

bool History::init()
{
    if (!Node::init())
    {
        return false;
    }

    createHistory();

    return true;
}

void History::createHistory()
{
    history = Sprite::create("sprites/background/history.png");

    this->addChild(history);
}