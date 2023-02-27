#include "FightScene.h"

Scene* FightScene::createScene()
{
    // Preload the background music
   
    // Preload click sound

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
}

void FightScene::addBackground()
{
    battleZoneBackground.createBackgroundEuphoria();

    battleZoneBackground.getBackgroundEuphoria()->setPosition(backgroundPosition);

    this->addChild(battleZoneBackground.getBackgroundEuphoria());
}

void FightScene::addEntities()
{
    m_entitiesFight = EntitiesFight::create();

    this->addChild(m_entitiesFight);
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
    addEntities();
    addActionBar();

    EntitiesFight monster, protagonist;

    //monster.attack(protagonist);
}