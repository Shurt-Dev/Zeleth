#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "ui/UIButton.h"

#include "GameScene.h"
//#include "Settings.h"
#include "AudioSettings.h"

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
    void setupAudioSettings();

    CREATE_FUNC(MenuScene);

private:
    Size visibleSize;
    Vec2 origin;
    Vec2 center;
    Vec2 bottomRight;

    AudioSettings* audioSettings;

    Sprite* background;

    Button* startButton;
    Button* quitButton;
};