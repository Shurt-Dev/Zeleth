#pragma once
#include "FightScene.h"

Scene* FightScene::createScene()
{
    return FightScene::create();
}

bool FightScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    dataScreenPosition();

    gameLoop();

    return true;
}

void FightScene::dataScreenPosition()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    backgroundPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    actionBarPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2 - 440);
    enemyPosition = Vec2(1300, 750);
    ally = Vec2(0, 0);
}

void FightScene::addBackground()
{
    battleZoneBackground.createBackgroundEuphoria();

    battleZoneBackground.getBackgroundEuphoria()->setPosition(backgroundPosition);

    this->addChild(battleZoneBackground.getBackgroundEuphoria());
}

void FightScene::addActionBar()
{
    m_actionBar = ActionBar::create();

    m_actionBar->setPosition(actionBarPosition);

    this->addChild(m_actionBar);
}

void FightScene::gameLoop()
{
    addBackground();
    addActionBar();

    m_meupette = Meupette::create();
    this->addChild(m_meupette);

    m_iop = ProtagonistFight::create();
    this->addChild(m_iop);

    // set position
    m_meupette->setPosition(enemyPosition);

    m_iop->attack(m_meupette);
    m_meupette->attack(m_iop);

    /*m_meupette->getIdleAnimation();*/
}