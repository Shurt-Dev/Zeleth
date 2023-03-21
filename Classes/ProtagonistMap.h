#include "cocos2d.h"

#include "AnimationsProtagonistMap.h"

USING_NS_CC;

class ProtagonistMap : public Sprite
{
public:
	virtual bool init();

	void createAnimations();

	void setScreenPosition();

	void setKeyboardInput();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	void update(float delta);

	CREATE_FUNC(ProtagonistMap);

private:
	EventListenerKeyboard* listener;
	AnimationsProtagonistMap* m_animation;

	Size visibleSize;
	Vec2 origin;
	Vec2 center;

	Vec2 movement;

	Vec2 lastMovementDirection;

	bool _isKeyUpPressed;
	bool _isKeyRightPressed;
	bool _isKeyDownPressed;
	bool _isKeyLeftPressed;

	int _movementSpeed;
};