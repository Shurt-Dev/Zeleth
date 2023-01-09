#include "IntroScene.h"

using namespace CocosDenshion;

Scene* IntroScene::createScene()
{
    // Preload logo intro sound
    SimpleAudioEngine::getInstance()->preloadEffect("sound/sfx/intro-logo-infinity-game.mp3");

    return IntroScene::create();
}

bool IntroScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Determine the center coordinates of the screen
    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    _center = Vec2(_origin.x + _visibleSize.width / 2, _origin.y + _visibleSize.height / 2);

    animateTitle();
    animateTransition();

    return true;
}

void IntroScene::animateTitle()
{
    // Title Infinity Games
    auto title = Label::createWithTTF("Infinity Games", "fonts/studio.ttf", 120);
    title->setOpacity(0);
    title->setPosition(_center);

    this->addChild(title);

    auto startDelay = DelayTime::create(0.5f);
    auto fadeIn = FadeIn::create(1.0f);
    auto delayTitle = DelayTime::create(2.0f);
    auto fadeOut = FadeOut::create(1.0f);
    auto animationTitle = Sequence::create(startDelay, fadeIn, delayTitle, fadeOut, nullptr);

    title->runAction(animationTitle);
}

void IntroScene::animateTransition()
{
    // run music effect
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/intro-logo-infinity-game.mp3");

    auto delayTransistionScene = DelayTime::create(5);
    auto replace = CallFunc::create([]() 
    {
        Director::getInstance()->replaceScene(MenuScene::createScene());
    });

    auto transistionScene = Sequence::create(delayTransistionScene, replace, nullptr);
    this->runAction(transistionScene);
}