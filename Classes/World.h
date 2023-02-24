#include "cocos2d.h"

#include "TileMap.h"
#include "EntitiesMap.h"

USING_NS_CC;

class World : public Node
{
public:
	virtual bool init();

	void createEuphoriaTileMap();
	void createProtagonist();

	void createCamera();

	CREATE_FUNC(World);
	
private:
	Follow* m_follow;

	EntitiesMap entities;
	TileMap tileMap;
};