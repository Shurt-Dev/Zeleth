#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

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

    void fightLoop();

    void getInitiator();

    CREATE_FUNC(FightScene);
        
private:
    Meupette* m_meupette;
    ProtagonistFight* m_oskar_khas;

    ActionBar* m_actionBar;

    BattleZoneBackground battleZoneBackground;

    Size visibleSize;
    Vec2 backgroundPosition;
    Vec2 actionBarPosition;
    Vec2 enemyPosition;
    Vec2 allyPosition;

    int turn;
    bool playerInitiator;


    // debug
    Action* idleActionEnemy;
    Action* attackActionEnemy;


    Attack* attack;
    Button* attackButton;
};