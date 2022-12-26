#include "cocos2d.h"

USING_NS_CC;

class TileMap : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // Chargement de la carte à tuiles
    void loadTileMap();

    // implement the "static create()" method manually
    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* _tileMap;
};

