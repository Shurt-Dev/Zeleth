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

	void Quit();

	void Menu();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	CREATE_FUNC(GameSettings);
};

