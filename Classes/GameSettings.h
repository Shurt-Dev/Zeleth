#pragma once
#include "cocos2d.h"

USING_NS_CC;

class GameSettings : public Node
{
public:
	virtual bool init();

	void pauseCallback();

	void resumeCallback();

	void setupKeyboardInput();

	void quit();

	void goToMenu();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	CREATE_FUNC(GameSettings);

private:
	EventListenerKeyboard* listener;
	Label* label;
	Scene* menuScene;
	Menu* menu;

	Size visibleSize;
	Vec2 origin;
	Vec2 center;
	Vec2 bottomRight;

};

