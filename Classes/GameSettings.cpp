#include "GameSettings.h"

#include "MenuScene.h"

bool GameSettings::init()
{
	if (!Node::init())
	{
		return false;
	}

    setupKeyboardInput();

	return true;
}

void GameSettings::setupKeyboardInput()
{
    // keys
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameSettings::onKeyPressed, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    //this->scheduleUpdate();
}

void GameSettings::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        pauseCallback();
    }
}

void GameSettings::pauseCallback()
{
    this->pause();

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    Vec2 bottomRight = origin + Vec2(visibleSize.width, 0);

    Label* label = cocos2d::Label::createWithSystemFont("Paused", "Arial", 24);
    label->setPosition(Vec2(center.x, center.y + 100));

    MenuItemFont* menuItem = cocos2d::MenuItemFont::create("Resume", CC_CALLBACK_0(GameSettings::resumeCallback, this));
    menuItem->setPosition(Vec2(center.x, center.y + 50));

    MenuItemFont* menuItem1 = cocos2d::MenuItemFont::create("Menu", CC_CALLBACK_0(GameSettings::Menu, this));
    menuItem1->setPosition(center);

    MenuItemFont* menuItem2 = cocos2d::MenuItemFont::create("Quit", CC_CALLBACK_0(GameSettings::Quit, this));
    menuItem2->setPosition(Vec2(center.x, center.y - 50));

    Sprite* menuBackground = Sprite::create("sprites/ui/menu/blue-square.jpg", Rect(0, 0, 150, 200));
    menuBackground->setPosition(Vec2(center.x, center.y+20));

    cocos2d::Menu* menu = cocos2d::Menu::create(menuItem, menuItem1, menuItem2, nullptr);
    menu->setPosition(cocos2d::Vec2::ZERO);
    menu->setContentSize(cocos2d::Size(480, 320));
    this->addChild(menu,1);
    this->addChild(label,1);
    this->addChild(menuBackground,0);
    return;
}

void GameSettings::resumeCallback()
{
    this->resume();
    this->removeAllChildren();
}

void GameSettings::Quit()
{
    exit(0);
}

void GameSettings::Menu()
{
    auto menu = MenuScene::createScene();

    Director::getInstance()->replaceScene(menu);
}