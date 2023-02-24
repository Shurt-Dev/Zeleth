#include "cocos2d.h"

#include "ProtagonistMap.h"

USING_NS_CC;

class EntitiesMap : public Node
{
public:
	virtual bool init();

	void createProtagonist();
	ProtagonistMap* setProtagonist();

	CREATE_FUNC(EntitiesMap);

private:
	ProtagonistMap* m_protagonist;
};