#include "MainCharacter.h"

USING_NS_CC;

// Crée un nouveau personnage
MainCharacter* MainCharacter::create()
{
    MainCharacter* pSprite = new MainCharacter();
    if (pSprite->init())
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return nullptr;
}

bool MainCharacter::init()
{
    if (!Sprite::init())
        return false;

    // Création du sprite pour le personnage
    _sprite = Sprite::create("Player.png");

    // Ajout du sprite au noeud de la classe MainCharacter
    this->addChild(_sprite);

    // Determine the center coordinates of the screen
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    // Position the main character at the center of the screen
    this->setPosition(center);

    //// Zoom sur le personnage d'un facteur de 5,0
    //_sprite->setScale(5.0);

    return true;
}
