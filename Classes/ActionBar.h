#include "cocos2d.h"

#include "History.h"
#include "Actions.h"
#include "SelectAction.h"

USING_NS_CC;

class ActionBar : public Node
{
public:
	virtual bool init();

	void createActionBar();

	CREATE_FUNC(ActionBar);

private:
	History history;
	Actions actions;
	SelectAction selectAction;
};