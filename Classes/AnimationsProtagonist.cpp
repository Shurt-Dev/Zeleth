#include "AnimationsProtagonist.h"

bool AnimationsProtagonist::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}

void AnimationsProtagonist::loadAnimations()
{
    // Load the sprite sheet that contains the frames for the main character animation
    this->spritecache = SpriteFrameCache::getInstance();
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/down/mainCharacter-down.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/up/mainCharacter-up.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/left/mainCharacter-left.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/right/mainCharacter-right.plist");
}

std::string AnimationsProtagonist::getStartRotation()
{
    return "mainCharacter-down-1.png";
}