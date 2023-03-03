#pragma once

#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class EntitiesFight
{
public:
	void takeDamage(float nbDegats);
	void attack(EntitiesFight& cible);
	bool isAlive();

	virtual float Level();
	virtual float Life();
	virtual float Damage();
	virtual float Initiative();
	virtual string Name();

protected:
	string name;
	float level;
	float life;
	float damage;
	float initiative;
};