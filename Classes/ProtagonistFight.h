#pragma once

#include "cocos2d.h"
#include "EntitiesFight.h"

USING_NS_CC;

class ProtagonistFight : public EntitiesFight, public Sprite
{
public:
	virtual bool init();

	CREATE_FUNC(ProtagonistFight);

private:

};