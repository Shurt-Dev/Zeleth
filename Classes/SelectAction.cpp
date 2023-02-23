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
    this->addChild(attackButton);
    this->addChild(bagButton);
    this->addChild(infosButton);
    this->addChild(runButton);
}

void SelectAction::createAttackButton()
{
    attackButton = Button::create("normal.png", "pressed.png", "disabled.png");

    attackButton->setPosition(Vec2());
}

void SelectAction::createBagButton()
{
    bagButton = Button::create("normal.png", "pressed.png", "disabled.png");

    bagButton->setPosition(Vec2());
}

void SelectAction::createInfosButton()
{
    infosButton = Button::create("normal.png", "pressed.png", "disabled.png");

    infosButton->setPosition(Vec2());
}

void SelectAction::createRunButton()
{
    runButton = Button::create("normal.png", "pressed.png", "disabled.png");

    runButton->setPosition(Vec2());
}