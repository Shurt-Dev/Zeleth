#include "TileMap.h"

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    // Charger la carte à tuiles
    loadTileMap();

    // Charger le personnage principal
    loadMainCharacter();

    // scale tilemap
    enlargeTileMap(4.0f);

    // start position
    moveToStartPoint();

    // Setup keyboard input
    setupKeyboardInput();

    // set movement speed
    _movementSpeed = 3;

    _isKeyUpPressed = false;
    _isKeyRightPressed = false;
    _isKeyDownPressed = false;
    _isKeyLeftPressed = false;

    return true;
}

void TileMap::loadTileMap()
{
    // Chargement de la carte à tuiles à partir d'un fichier .tmx
    _tileMap = TMXTiledMap::create("tiled/map.tmx");
    // ajout de la carte à tuiles à la scène
    this->addChild(_tileMap);
}

void TileMap::loadMainCharacter()
{
    // Création de l'objet MainCharacter
    mainCharacter = MainCharacter::create();

    // Récupération de la taille de l'écran visible
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // Calcul de la position du personnage au milieu de l'écran
    Vec2 characterPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2);

    // Définition de la position du personnage
    mainCharacter->setPosition(characterPosition);

    // ajout de MainCharacter à la scène
    this->addChild(mainCharacter);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}

void TileMap::moveToStartPoint()
{
    // Obtain the object group named "Objects"
    TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects");

    // Obtain the object named "SpawnPoint" from the object group
    ValueMap spawnPoint = objectGroup->getObject("StartPoint");

    // Retrieve the x and y coordinates of the SpawnPoint object
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();

    // Calculate the distance that the tile map needs to be moved to center the SpawnPoint object
    Size visibleSize = Director::getInstance()->getVisibleSize();
    float xMovement = visibleSize.width / 2 - x*4;
    float yMovement = visibleSize.height / 2 - y*4;

    // Move the tile map by the necessary distance
    _tileMap->setPosition(_tileMap->getPosition() + Vec2(xMovement, yMovement));
}

void TileMap::setupKeyboardInput()
{
    // keys
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(TileMap::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(TileMap::onKeyReleased, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();
}

void TileMap::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isKeyLeftPressed = true;
        mainCharacter->runAction(RepeatForever::create(mainCharacter->getLeftWalkAnimation()));
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isKeyRightPressed = true;
        mainCharacter->runAction(RepeatForever::create(mainCharacter->getRightWalkAnimation()));
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isKeyUpPressed = true;
        mainCharacter->runAction(RepeatForever::create(mainCharacter->getUpWalkAnimation()));
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isKeyDownPressed = true;
        mainCharacter->runAction(RepeatForever::create(mainCharacter->getDownWalkAnimation()));
        break;
    default:
        break;

    }
}

void TileMap::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isKeyLeftPressed = false;

        mainCharacter->stopAllActions();
        mainCharacter->setSpriteFrame("mainCharacter-left-1.png");

        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isKeyRightPressed = false;

        mainCharacter->stopAllActions();
        mainCharacter->setSpriteFrame("mainCharacter-right-1.png");

        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isKeyUpPressed = false;

        mainCharacter->stopAllActions();
        mainCharacter->setSpriteFrame("mainCharacter-up-1.png");

        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isKeyDownPressed = false;

        mainCharacter->stopAllActions();
        mainCharacter->setSpriteFrame("mainCharacter-down-1.png");

        break;
    default:
        break;
    }
}

void TileMap::update(float delta)
{
    Vec2 movement = Vec2::ZERO;

    if (_isKeyLeftPressed)
    {
        movement.x = 1;
    }
    else if (_isKeyRightPressed)
    {
        movement.x = -1;
    }
    else if (_isKeyUpPressed)
    {
        movement.y = -1;
    }
    else if (_isKeyDownPressed)
    {
        movement.y = 1;
    }

    // s'assurer que movement ne contient qu'une seule valeur non nulle
    if (movement.x != 0 && movement.y != 0)
    {
        movement.x = 0;
    }

    // mettre à jour la position du _tileMap par pixel et à chaque frame
    _tileMap->setPosition(_tileMap->getPosition() + movement * _movementSpeed);
}

