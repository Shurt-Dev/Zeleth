#include "cocos2d.h"

#include "World.h"

#include "TileMap.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
    // Instance de la classe TileMap
    TileMap* _tileMap;
};