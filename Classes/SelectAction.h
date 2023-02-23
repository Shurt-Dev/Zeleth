#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class SelectAction : public Node
{
public:
	virtual bool init();

	void createSelectAction();

	void createAttackButton();
	void createBagButton();
	void createInfosButton();
	void createRunButton();

	CREATE_FUNC(SelectAction);
private:
	Sprite* selectAction;
	Button* attackButton;
	Button* bagButton;
	Button* infosButton;
	Button* runButton;
};