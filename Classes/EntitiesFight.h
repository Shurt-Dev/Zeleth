#pragma once
#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class EntitiesFight
{
public:
	virtual float Level();
	virtual float Life();
	virtual float Damage();
	virtual float Initiative();
	virtual string Name();
	virtual bool IsEnemy();

	void getAttackAnimation();

	void takeDamage(float nbDamage);
	void attack(EntitiesFight* target);
	bool isAlive();

protected:
	string name;
	float level;
	float life;
	float damage;
	float initiative;
	bool isEnemy;
};