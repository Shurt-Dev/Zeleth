#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class SelectAction : public Node
{
public:
	virtual bool init();

	void createAttackButton();
	void createBagButton();
	void createInfosButton();
	void createRunButton();

	Button* getAttackButton();
	Button* getBagButton();
	Button* getInfosButton();
	Button* getRunButton();

	CREATE_FUNC(SelectAction);

private:
	Button* m_attackButton;
	Button* m_bagButton;
	Button* m_infosButton;
	Button* m_runButton;
	Button* m_buttonEvent;
};