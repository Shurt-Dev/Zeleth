#include "cocos2d.h"
#include <string>

USING_NS_CC;

class AnimationsProtagonist : public Sprite
{
public:
	virtual bool init();

    void loadAnimations();
    std::string getStartRotation();

    // Création de l'objet
    CREATE_FUNC(AnimationsProtagonist);

private:
    SpriteFrameCache* spritecache;
};