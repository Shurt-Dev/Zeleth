#include "cocos2d.h"

USING_NS_CC;

class SelectAction : public Node
{
public:
	virtual bool init();

	void createSelectAction();

	Sprite* getSelectAction();

	CREATE_FUNC(SelectAction);
private:
	Sprite* selectAction;
};