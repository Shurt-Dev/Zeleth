#ifndef __MAP_SCENE_H__
#define __MAP_SCENE_H__

#include "cocos2d.h"
#include "MainCharacter.h"

USING_NS_CC;

class MapScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    void update(float delta);

    // implement the "static create()" method manually
    CREATE_FUNC(MapScene);

private:
    MainCharacter* mainCharacter;

    TMXTiledMap* _tileMap;

    //collisions tiles
    TMXLayer* _meta;

    bool _isLeftPressed;
    bool _isRightPressed;
    bool _isUpPressed;
    bool _isDownPressed;

    int _movementSpeed;
};

#endif // __MAP_SCENE_H__
