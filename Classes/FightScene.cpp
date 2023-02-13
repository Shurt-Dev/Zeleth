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

void FightScene::createBackground()
{
    m_battleZoneBackground.createBackgroundEuphoria();

    m_battleZoneBackground.getBackgroundEuphoria()->setPosition(backgroundPosition);

    this->addChild(m_battleZoneBackground.getBackgroundEuphoria());
}

void FightScene::createActionBar()
{
    auto actionBar = Sprite::create("sprites/background/action_bar-test.jpg");

    actionBar->setPosition(actionBarPosition);

    this->addChild(actionBar);
}

void FightScene::gameLoop()
{
    createBackground();
    createActionBar();
}