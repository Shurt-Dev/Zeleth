#pragma once

#include "cocos2d.h"

class MainCharacter : public cocos2d::Sprite
{
public:
    // Crée un nouveau personnage
    static MainCharacter* create();

    // Initialise le personnage
    virtual bool init();

private:
    // Sprite du personnage
    cocos2d::Sprite* _sprite;
};