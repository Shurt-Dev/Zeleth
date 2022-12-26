#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
    TMXTiledMap* _tileMap;
};

#endif // __GAME_SCENE_H__
