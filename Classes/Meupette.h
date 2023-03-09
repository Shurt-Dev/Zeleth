#pragma once

#include "cocos2d.h"
#include "EntitiesFight.h"

USING_NS_CC;

class Meupette : public EntitiesFight, public Sprite
{
public:
	virtual bool init();

	void loadAnimation();

	Action* getIdleAnimation();
	Action* getAttackAnimation();

	CREATE_FUNC(Meupette);

private:

	SpriteFrameCache* spritecache;

	Animation* attackAnimation;
	Animate* attackAnimate;

	Animation* idleAnimation;
	Animate* idleAnimate;

};
