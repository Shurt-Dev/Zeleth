#include "cocos2d.h"
#include "AnimationsProtagonistMap.h"
#include "TileMap.h"

USING_NS_CC;

class Collisions : public Node
{
public:
	virtual bool init();

	void CollisionDetection();

	CREATE_FUNC(Collisions);

private:

};