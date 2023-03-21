#pragma once
#include "cocos2d.h"

#include "World.h"

#include "GameSettings.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void main();

    void createIsland();

    CREATE_FUNC(GameScene);

private:
    World* m_world;

    GameSettings* _settings;
};