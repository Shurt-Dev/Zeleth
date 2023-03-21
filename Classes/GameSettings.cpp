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
    listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameSettings::onKeyPressed, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
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

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    bottomRight = origin + Vec2(visibleSize.width, 0);

    label = Label::createWithSystemFont("Paused", "Arial", 24);
    label->setPosition(Vec2(center.x, center.y + 100));

    MenuItemFont* menuItem = MenuItemFont::create("Resume", CC_CALLBACK_0(GameSettings::resumeCallback, this));
    menuItem->setPosition(Vec2(center.x, center.y + 50));

    MenuItemFont* menuItem1 = MenuItemFont::create("Menu", CC_CALLBACK_0(GameSettings::goToMenu, this));
    menuItem1->setPosition(center);

    MenuItemFont* menuItem2 = MenuItemFont::create("Quit", CC_CALLBACK_0(GameSettings::quit, this));
    menuItem2->setPosition(Vec2(center.x, center.y - 50));

    Sprite* menuBackground = Sprite::create("sprites/ui/menu/blue-square.jpg", Rect(0, 0, 150, 200));
    menuBackground->setPosition(Vec2(center.x, center.y+20));

    menu = Menu::create(menuItem, menuItem1, menuItem2, nullptr);
    menu->setPosition(Vec2::ZERO);
    menu->setContentSize(Size(480, 320));
    this->addChild(menuBackground);
    this->addChild(menu,1);
    this->addChild(label,1);

    return;
}

void GameSettings::resumeCallback()
{
    this->resume();
    this->removeAllChildren();
}

void GameSettings::quit()
{
    exit(0);
}

void GameSettings::goToMenu()
{
    menuScene = MenuScene::createScene();

    Director::getInstance()->replaceScene(menuScene);
}