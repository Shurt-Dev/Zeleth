#include "cocos2d.h"

#include "TileMap.h"
#include "Entities.h"

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

	Entities entities;
	TileMap tileMap;
};