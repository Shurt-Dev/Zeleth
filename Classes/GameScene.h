#include "cocos2d.h"

#include "Island.h"

USING_NS_CC;

class GameScene : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void main();

    void createIsland();

    CREATE_FUNC(GameScene);

private:
    Island* m_island;
};