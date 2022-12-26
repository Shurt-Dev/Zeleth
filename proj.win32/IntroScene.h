#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class IntroScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void animateTitle();
    void animateTransition();

    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);

private:
    Size _visibleSize;
    Vec2 _origin;
    Vec2 _center;
};

#endif // __INTRO_SCENE_H__
