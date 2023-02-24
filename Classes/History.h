#include "cocos2d.h"

USING_NS_CC;

class History : public Node
{
public:
	virtual bool init();

	void createHistory();

	CREATE_FUNC(History);
private:
	Sprite* history;
};