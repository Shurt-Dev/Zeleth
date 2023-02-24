#include "cocos2d.h"

USING_NS_CC;

class Bag : public Node
{
public:
	virtual bool init();

	void createBagZone();

	Sprite* getBagZone();

	CREATE_FUNC(Bag);
private:
	Sprite* m_bagZone;
};