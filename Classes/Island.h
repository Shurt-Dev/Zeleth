#include "cocos2d.h"

USING_NS_CC;

class Island : public Node
{
public:
	virtual bool init();

	void loadMap();
	void setRenderScale();
	void setSpawnPointProtagonist();

	CREATE_FUNC(Island);

private:
	TMXTiledMap* m_islandMap;
	TMXObjectGroup* m_objectGroup;
	ValueMap spawnPoint;

	Vec2 startPosition;
	Size visibleSize;

	int xSpawnPoint;
	int ySpawnPoint;

	float xMovement;
	float yMovement;
};