#include "Protagonist.h"

bool Protagonist::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    setAnimations();
    setStartRotation();

    return true;
}

void Protagonist::setAnimations()
{
    animation.loadAnimations();
}

void Protagonist::setStartRotation()
{
    this->setSpriteFrame(animation.getStartRotation());
}