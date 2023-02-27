#include "cocos2d.h"
#include <string>

USING_NS_CC;
using namespace std;

class EntitiesFight : public Node
{
public:
	virtual bool init();

	void takeDamage(float nbDegats);
	void attack(EntitiesFight cible);
	bool isAlive();

	CREATE_FUNC(EntitiesFight);

protected:
	string name;
	float level;
	float life;
	float damage;
	float initiative;
};