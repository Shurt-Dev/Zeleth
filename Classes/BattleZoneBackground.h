#include "cocos2d.h"

USING_NS_CC;

class BattleZoneBackground : public Node
{
public:
	virtual bool init();

	Sprite* getBackgroundEuphoria();
	void createBackgroundEuphoria();

	CREATE_FUNC(BattleZoneBackground);

private:
	Sprite* m_background;
};