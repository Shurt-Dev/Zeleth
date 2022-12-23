#include "IntroScene.h"

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

bool IntroScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Determine the center coordinates of the screen
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    auto title = Label::createWithTTF("Infinity Games", "fonts/studio.ttf", 120);
    title->setOpacity(0);
    title->setPosition(center);
    this->addChild(title);

    auto fadeIn = FadeIn::create(2.0f);
    auto delayTitle = DelayTime::create(2.5);
    auto fadeOut = FadeOut::create(0.5f);
    auto animationTitle = Sequence::create(fadeIn, delayTitle, fadeOut, nullptr);

    title->runAction(animationTitle);

    auto delayTransistionScene = DelayTime::create(5);
    auto replace = CallFunc::create([&]() {
        Director::getInstance()->replaceScene(MenuScene::createScene());
        });

    auto transistionScene = Sequence::create(delayTransistionScene, replace, nullptr);
    this->runAction(transistionScene);

    return true;
}