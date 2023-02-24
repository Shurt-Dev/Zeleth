#include "SelectAction.h"

bool SelectAction::init()
{
    if (!Node::init())
    {
        return false;
    }

    createAttackButton();
    createBagButton();
    createInfosButton();
    createRunButton();

    return true;
}

void SelectAction::createAttackButton()
{
    m_attackButton = Button::create("sprites/background/button_attack.png", "", "");

    m_attackButton->setPosition(Vec2(-100, 50));

    this->addChild(m_attackButton);
}

void SelectAction::createBagButton()
{
    m_bagButton = Button::create("sprites/background/button_bag.png", "", "");

    m_bagButton->setPosition(Vec2(100, 50));

    this->addChild(m_bagButton);
}

void SelectAction::createInfosButton()
{
    m_infosButton = Button::create("sprites/background/button_infos.png", "", "");

    m_infosButton->setPosition(Vec2(-100, -50));
    
    this->addChild(m_infosButton);
}

void SelectAction::createRunButton()
{
    m_runButton = Button::create("sprites/background/button_run.png", "", "");

    m_runButton->setPosition(Vec2(100, -50));
    
    this->addChild(m_runButton);
}

Button* SelectAction::getAttackButton()
{
    return m_attackButton;
}

Button* SelectAction::getBagButton()
{
    return m_bagButton;
}

Button* SelectAction::getInfosButton()
{
    return m_infosButton;
}

Button* SelectAction::getRunButton()
{
    return m_runButton;
}