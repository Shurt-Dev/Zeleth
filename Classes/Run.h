#include "cocos2d.h"

USING_NS_CC;

class Run : public Node
{
public:
	virtual bool init();

	void createRunZone();

	Sprite* getRunZone();

	CREATE_FUNC(Run);

private:
	Sprite* m_runZone;
};