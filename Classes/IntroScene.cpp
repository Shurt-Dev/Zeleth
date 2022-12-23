#include "IntroScene.h"

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

bool IntroScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    

    return true;
}