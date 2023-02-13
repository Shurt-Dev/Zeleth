#include "cocos2d.h"

USING_NS_CC;

class History : public Node
{
public:
	virtual bool init();

	void createHistory();

	Sprite* getHistory();

	CREATE_FUNC(History);
private:
	Sprite* history;
};