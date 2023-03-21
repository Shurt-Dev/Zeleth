#include "cocos2d.h"

#include "History.h"
#include "SelectAction.h"
#include "Attack.h"
#include "Bag.h"
#include "Infos.h"
#include "Run.h"

USING_NS_CC;

class ActionBar : public Node
{
public:
	virtual bool init();

	void createActionBar();

	void actionsState();

	CREATE_FUNC(ActionBar);

private:
	SelectAction* m_selectAction;
	History* m_history;
	Attack* m_attack;
	Bag* m_bag;
	Infos* m_infos;
	Run* m_run;
};