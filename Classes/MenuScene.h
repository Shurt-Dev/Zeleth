#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "Settings.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace ui;

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

    void setupSettings();

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

private:
    Size _visibleSize;
    Vec2 _origin;
    Vec2 _center;
    Vec2 _bottomRight;

    Settings* _settings;
};