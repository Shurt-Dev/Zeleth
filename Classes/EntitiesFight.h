#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class EntitiesFight
{
public:
	virtual void takeDamage(float nbDegats);
	virtual void attack(EntitiesFight cible);
	virtual bool isAlive();

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