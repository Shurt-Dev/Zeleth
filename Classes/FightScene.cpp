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
    backgroundPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100);
    actionBarPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2 - 440);
}

void FightScene::addBackground()
{
    battleZoneBackground.createBackgroundEuphoria();

    battleZoneBackground.getBackgroundEuphoria()->setPosition(backgroundPosition);

    this->addChild(battleZoneBackground.getBackgroundEuphoria());
}

void FightScene::addActionBar()
{
    actionBar = ActionBar::create();

    actionBar->setPosition(actionBarPosition);

    this->addChild(actionBar);
}

void FightScene::gameLoop()
{
    addBackground();
    addActionBar();
}