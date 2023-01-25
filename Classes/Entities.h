#include "cocos2d.h"

#include "Protagonist.h"

USING_NS_CC;

class Entities : public Node
{
public:
	virtual bool init();

	void createProtagonist();
	Protagonist* setProtagonist();

	CREATE_FUNC(Entities);

private:
	Protagonist* m_protagonist;
};