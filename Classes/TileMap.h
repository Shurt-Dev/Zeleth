#include "cocos2d.h"

#include "MainCharacter.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    virtual bool init();

    void loadTileMap();

    void loadMainCharacter();

    void enlargeTileMap(float scale);
    void moveToStartPoint();

    void setupKeyboardInput();

    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    void update(float delta);

    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;

    MainCharacter* mainCharacter;

    Vec2 lastMovementDirection;

    bool _isKeyUpPressed;
    bool _isKeyRightPressed;
    bool _isKeyDownPressed;
    bool _isKeyLeftPressed;

    int _movementSpeed;
};