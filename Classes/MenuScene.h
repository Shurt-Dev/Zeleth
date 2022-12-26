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

    void createTitle();
    void setupAudio();
    void setupBackground();
    void setupQuitButton();
    void setupStartButton();
    void setupSettingsButton();

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

private:
    Size _visibleSize;
    Vec2 _origin;
    Vec2 _center;
    Vec2 _bottomRight;
};

#endif // __MENU_SCENE_H__
