#include "cocos2d.h"

USING_NS_CC;

class Attack : public Node
{
public:
	virtual bool init();

	void createAttackZone();

	Sprite* getAttackZone();

	CREATE_FUNC(Attack);

private:
	Sprite* m_attackZone;
};