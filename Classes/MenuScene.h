#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "MapScene.h"

USING_NS_CC;

class MenuScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void onStartClicked(Ref* sender);
    void onSettingsClicked(Ref* sender);
    void onQuitClicked(Ref* sender);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif // __MENU_SCENE_H__
