#include "cocos2d.h"

USING_NS_CC;

class Actions : public Node
{
public:
	virtual bool init();

	void createActions();

	Sprite* getActions();

	CREATE_FUNC(Actions);
private:
	Sprite* actions;
};