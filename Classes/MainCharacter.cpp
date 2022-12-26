#include "MainCharacter.h"

bool MainCharacter::init()
{
    // appeler la méthode init de la superclasse
    if (!Sprite::init())
    {
        return false;
    }

    // Création du sprite à partir de l'image "sprite.png"
    this->initWithFile("sprites/characters/sprite-resize.png");

    // Détermination de la taille de l'écran
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // Définition de la position du sprite au milieu de l'écran
    this->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

    return true;
}