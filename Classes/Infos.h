#include "cocos2d.h"

USING_NS_CC;

class Infos : public Node
{
public:
	virtual bool init();

	void createInfosZone();

	Sprite* getInfosZone();

	CREATE_FUNC(Infos);
private:
	Sprite* m_infosZone;
};