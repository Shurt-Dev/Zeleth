#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "ActionBar.h"
#include "BattleZoneBackground.h"

USING_NS_CC;

class FightScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void dataScreenPosition();

    void createBackground();
    void createActionBar();

    void gameLoop();

    CREATE_FUNC(FightScene);

private:
    BattleZoneBackground m_battleZoneBackground;

    Size visibleSize;
    Vec2 backgroundPosition;
    Vec2 actionBarPosition;
};