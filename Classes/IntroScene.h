#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
//#include "MapSceneCharacter.h"

USING_NS_CC;

class IntroScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);
};

#endif // __INTRO_SCENE_H__
