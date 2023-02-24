#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "ActionBar.h"
#include "BattleZoneBackground.h"
#include "EntitiesFight.h"

USING_NS_CC;

class FightScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void dataScreenPosition();

    void addBackground();
    void addActionBar();
    void addEntities();

    void gameLoop();

    CREATE_FUNC(FightScene);

private:
    ActionBar* m_actionBar;
    EntitiesFight* m_entitiesFight;

    BattleZoneBackground battleZoneBackground;

    Size visibleSize;
    Vec2 backgroundPosition;
    Vec2 actionBarPosition;
};