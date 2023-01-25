#include "cocos2d.h"

USING_NS_CC;

class TileMap : public Node
{
public:
    virtual bool init();

    void loadEuphoriaTileMap();

    TMXTiledMap* getEuphoriaMap();

    CREATE_FUNC(TileMap);

private:
    TMXTiledMap* m_euphoriaTileMap;
};