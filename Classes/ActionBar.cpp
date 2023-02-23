#include "ActionBar.h"

bool ActionBar::init()
{
    if (!Node::init())
    {
        return false;
    }

    createActionBar();

    return true;
}

void ActionBar::createActionBar()
{
    history.createHistory();
    actions.createActions();
    /*selectAction.createSelectAction();*/

    history.getHistory()->setPosition(Vec2(-760, 0));
    actions.getActions()->setPosition(Vec2(0, 0));
    /*selectAction.getSelectAction()->setPosition(Vec2(760, 0));*/

    this->addChild(history.getHistory());
    this->addChild(actions.getActions());
    /*this->addChild(selectAction.getSelectAction());*/
}