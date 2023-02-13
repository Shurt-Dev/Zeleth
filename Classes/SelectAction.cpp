#include "SelectAction.h"

bool SelectAction::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void SelectAction::createSelectAction()
{
    selectAction = Sprite::create("sprites/background/select_action.jpg");
}

Sprite* SelectAction::getSelectAction()
{
    return selectAction;
}