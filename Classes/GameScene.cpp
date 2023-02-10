#include "GameScene.h"

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    main();

    _settings = GameSettings::create();

    this->addChild(_settings);

    return true;
}

void GameScene::main()
{
    // set up scene
    createIsland();
}

void GameScene::createIsland()
{
    m_world = World::create();

    this->addChild(m_world);
}