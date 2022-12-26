#include "GameScene.h"

Scene* GameScene::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = GameScene::create();

    // ajouter la couche à la scène
    scene->addChild(layer);

    // retourner la scène
    return scene;
}

// surcharge de la méthode init
bool GameScene::init()
{
    // appeler la méthode init de la superclasse
    if (!Scene::init())
    {
        return false;
    }

    // Création de l'instance de TileMap
    _tileMap = TileMap::create();
    // ajout de la carte à tuiles à la scène
    this->addChild(_tileMap);

    // Création de l'objet MainCharacter
    auto mainCharacter = MainCharacter::create();
    // ajout de MainCharacter à la scène
    this->addChild(mainCharacter);

    /*mainCharacter->setPosition(Vec2(100, 100));*/

    return true;
}