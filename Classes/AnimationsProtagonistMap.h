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
    IdleDown = 8
};

class AnimationsProtagonistMap : public Sprite
{
public:
	virtual bool init();

    void loadAnimations();
    void getStartRotation();

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

    // Création de l'objet
    CREATE_FUNC(AnimationsProtagonistMap);

private:
    SpriteFrameCache* spritecache;

    AnimationState _animationState;
};