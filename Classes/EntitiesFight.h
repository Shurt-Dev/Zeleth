#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace std;

class EntitiesFight
{
public:
	void takeDamage(float nbDegats);
	void attack(EntitiesFight cible);
	bool isAlive();

	float Level();
	float Life();
	float Damage();
	float Initiative();
	string Name();

protected:
	string name;
	float level;
	float life;
	float damage;
	float initiative;
};