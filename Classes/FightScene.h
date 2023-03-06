#pragma once

#include "cocos2d.h"

#include "ActionBar.h"
#include "BattleZoneBackground.h"

#include "ProtagonistFight.h"
#include "Meupette.h"

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
    Meupette* m_meupette;
    ProtagonistFight* m_iop;

    ActionBar* m_actionBar;

    BattleZoneBackground battleZoneBackground;

    Size visibleSize;
    Vec2 backgroundPosition;
    Vec2 actionBarPosition;
    Vec2 enemyPosition;
    Vec2 ally;
};