#include "cocos2d.h"

USING_NS_CC;

enum class AnimationState {
	Right = 1,
	Left = 2,
	Down = 3,
	Up = 4,
	IdleLeft = 5,
	IdleRight = 6,
	IdleUp = 7,
	IdleDown = 8,
};

class Protagonist : public Sprite
{
public:
	virtual bool init();

	void loadSpriteCache();
	void setUpScreenPosition();
	void startingRotation();

	const float getMovementSpeed();

	void getLeftWalkAnimation();
	void getRightWalkAnimation();
	void getDownWalkAnimation();
	void getUpWalkAnimation();

	void getIdleLeft();
	void getIdleRight();
	void getIdleUp();
	void getIdleDown();

	void setAnimationState(AnimationState state);
	void setAnimation(AnimationState state);

	CREATE_FUNC(Protagonist);

protected:
	SpriteFrameCache* m_spritecache;

	AnimationState animationState;

	// data screen position
	Size visibleSize;
	Vec2 visibleOrigin;
	Vec2 center;

	float movementSpeed;
};