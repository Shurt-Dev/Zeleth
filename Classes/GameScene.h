#include "cocos2d.h"

#include "GameUI.h"
#include "ExitGame.h"
#include "Island.h"
#include "Protagonist.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void getIsland();
    void getProtagonist();

    // intputs
    void setupKeyboardInput();
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    // update method
    void update(float delta);

    void initMap();
    void mapLoop();

    CREATE_FUNC(GameScene);

private:
    Island* m_island;
    Protagonist* m_protagonist;

    EventListenerKeyboard* m_listener;

    Vec2 lastMovementDirection;
    Vec2 movement;

    bool isKeyUpPressed;
    bool isKeyRightPressed;
    bool isKeyDownPressed;
    bool isKeyLeftPressed;
};