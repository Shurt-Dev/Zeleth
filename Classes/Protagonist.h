#include "cocos2d.h"

#include "MovementsProtagonist.h"
#include "AnimationsProtagonist.h"

USING_NS_CC;

class Protagonist : public Sprite
{
public:
	virtual bool init();

	void setAnimations();
	void setStartRotation();

	CREATE_FUNC(Protagonist);

private:
	SpriteFrameCache* m_spritecache;

	AnimationsProtagonist animation;
	MovementsProtagonist movements;
};