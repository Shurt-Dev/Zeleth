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
    this->addChild(m_bag);
    this->addChild(m_infos);
    this->addChild(m_run);

    m_attack->setVisible(true);
    m_bag->setVisible(false);
    m_infos->setVisible(false);
    m_run->setVisible(false);

    m_selectAction = SelectAction::create();
    m_selectAction->setPosition(Vec2(760, 0));
    this->addChild(m_selectAction);
}

void ActionBar::actionsState()
{
    m_selectAction->getAttackButton()->addClickEventListener([&](Ref* sender)
    {
        if (!m_attack->isVisible())
        {
            m_attack->setVisible(true);

            if (m_bag->isVisible())
            {
                m_bag->setVisible(false);
            }
            else if (m_infos->isVisible())
            {
                m_infos->setVisible(false);
            }
            else if (m_run->isVisible())
            {
                m_run->setVisible(false);
            }
        }
    });

    m_selectAction->getBagButton()->addClickEventListener([&](Ref* sender)
    {
        if (!m_bag->isVisible())
        {
            m_bag->setVisible(true);

            if (m_attack->isVisible())
            {
                m_attack->setVisible(false);
            }
            else if (m_infos->isVisible())
            {
                m_infos->setVisible(false);
            }
            else if (m_run->isVisible())
            {
                m_run->setVisible(false);
            }
        }
    });

    m_selectAction->getInfosButton()->addClickEventListener([&](Ref* sender)
    {
        if (!m_infos->isVisible())
        {
            m_infos->setVisible(true);

            if (m_bag->isVisible())
            {
                m_bag->setVisible(false);
            }
            else if (m_attack->isVisible())
            {
                m_attack->setVisible(false);
            }
            else if (m_run->isVisible())
            {
                m_run->setVisible(false);
            }
        }
    });

    m_selectAction->getRunButton()->addClickEventListener([&](Ref* sender)
    {
        if (!m_run->isVisible())
        {
            m_run->setVisible(true);

            if (m_bag->isVisible())
            {
                m_bag->setVisible(false);
            }
            else if (m_infos->isVisible())
            {
                m_infos->setVisible(false);
            }
            else if (m_attack->isVisible())
            {
                m_attack->setVisible(false);
            }
        }
    });
}