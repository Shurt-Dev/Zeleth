#include "cocos2d.h"

USING_NS_CC;

enum class AnimationState {
    Idle,
    Right,
    Left,
    Down,
    Up
};

class MainCharacter : public Sprite
{
public:
    virtual bool init();

    void startingRotation();

    void getLeftWalkAnimation();
    void getRightWalkAnimation();
    void getDownWalkAnimation();
    void getUpWalkAnimation();

    void setAnimationState(AnimationState state);
    void setAnimation(AnimationState state);

    // Méthodes de création de l'objet
    CREATE_FUNC(MainCharacter);

private:
    SpriteFrameCache* spritecache;

    AnimationState _animationState;
};