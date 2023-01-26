#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "MenuScene.h"

USING_NS_CC;

class IntroScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void createTitle();
    void animateTitle();

    void animateTransition();

    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);

private:
    Label* title;

    Size visibleSize;
    Vec2 origin;
    Vec2 center;
};