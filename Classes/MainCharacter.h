#include "cocos2d.h"

USING_NS_CC;

class MainCharacter : public Sprite
{
public:
    virtual bool init();

    void startingRotation();

    Animate* MainCharacter::getLeftWalkAnimation();
    Animate* MainCharacter::getRightWalkAnimation();
    Animate* MainCharacter::getDownWalkAnimation();
    Animate* MainCharacter::getUpWalkAnimation();

    // Méthodes de création de l'objet
    CREATE_FUNC(MainCharacter);

private:
    SpriteFrameCache* spritecache;
};
