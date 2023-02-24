#include "ActionBar.h"

bool ActionBar::init()
{
    if (!Node::init())
    {
        return false;
    }

    createActionBar();
    actionsState();

    return true;
}

void ActionBar::createActionBar()
{
    m_history = History::create();
    m_history->setPosition(Vec2(-760, 0));
    this->addChild(m_history);

    m_attack = Attack::create();
    m_bag = Bag::create();
    m_infos = Infos::create();
    m_run = Run::create();

    this->addChild(m_attack);

    m_selectAction = SelectAction::create();
    m_selectAction->setPosition(Vec2(760, 0));
    this->addChild(m_selectAction);
}

void ActionBar::actionsState()
{
    m_selectAction->getAttackButton()->addClickEventListener([this](Ref* sender)
    {

    });

    m_selectAction->getBagButton()->addClickEventListener([this](Ref* sender)
    {

    });

    m_selectAction->getInfosButton()->addClickEventListener([this](Ref* sender)
    {
       
    });

    m_selectAction->getRunButton()->addClickEventListener([this](Ref* sender)
    {
      
    });
}