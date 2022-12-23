#pragma once

#include "cocos2d.h"

USING_NS_CC;

class MainCharacter : public Sprite
{
public:
    // Crée un nouveau personnage
    static MainCharacter* create();

    // Initialise le personnage
    virtual bool init();

private:
    // Sprite du personnage
    Sprite* _sprite;
};