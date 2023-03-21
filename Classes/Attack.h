#include "cocos2d.h"
#include "ui/UIButton.h"

USING_NS_CC;

using namespace ui;

class Attack : public Node
{
public:
	virtual bool init();

	void createAttackZone();

	void createAttackButton();
	Button* getAttackButton();

	Sprite* getAttackZone();

	void button();

	CREATE_FUNC(Attack);

private:
	Sprite* m_attackZone;
	Button* m_attackButton;
};