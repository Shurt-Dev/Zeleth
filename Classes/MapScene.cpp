#include "MapScene.h"
#include "MainCharacter.h"

Scene* MapScene::createScene()
{
    return MapScene::create();
}

bool MapScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    //create a tile map
    _tileMap = TMXTiledMap::create("tiled/map.tmx");
    this->addChild(_tileMap);

    //zoom map
    _tileMap->setScale(5.0);

    _meta = _tileMap->getLayer("Meta");
    _meta->setVisible(false);

    // instanciez votre objet mainCharacter ici
    mainCharacter = MainCharacter::create();
    this->addChild(mainCharacter);

    //zoom map
    mainCharacter->setScale(5.0);

    // starting map position
    _tileMap->setPosition(_tileMap->getPosition() + Vec2(800,400));

    // set movement speed
    _movementSpeed = 50;

    // keys
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MapScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MapScene::onKeyReleased, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate(); // 

    bool _isLeftPressed = false;
    bool _isRightPressed = false;
    bool _isUpPressed = false;
    bool _isDownPressed = false;

    return true;
}

void MapScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isLeftPressed = true;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isRightPressed = true;
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isUpPressed = true;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isDownPressed = true;
        break;
    default:
        break;
    }
}

void MapScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isLeftPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isRightPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isUpPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isDownPressed = false;
        break;
    }
}

void MapScene::update(float delta)
{
    Vec2 movement = Vec2::ZERO;
    if (_isLeftPressed)
    {
        movement.x = 1;
    }
    if (_isRightPressed)
    {
        movement.x = -1;
    }
    if (_isUpPressed)
    {
        movement.y = -1;
    }
    if (_isDownPressed)
    {
        movement.y = 1;
    }

    // s'assurer que movement ne contient qu'une seule valeur non nulle
    if (movement.x != 0 && movement.y != 0)
    {
        movement.x = 0;
    }

    _tileMap->setPosition(_tileMap->getPosition() + movement * _movementSpeed * delta);
}
