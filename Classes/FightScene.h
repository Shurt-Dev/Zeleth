#pragma once

#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "ActionBar.h"
#include "BattleZoneBackground.h"

#include "ProtagonistFight.h"
#include "Monster.h"

USING_NS_CC;

class FightScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void dataScreenPosition();

    void addBackground();
    void addActionBar();

    void gameLoop();

    CREATE_FUNC(FightScene);
        
private:
    ActionBar* m_actionBar;

    BattleZoneBackground battleZoneBackground;

    Size visibleSize;
    Vec2 backgroundPosition;
    Vec2 actionBarPosition;
};