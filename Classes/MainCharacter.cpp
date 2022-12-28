#include "MainCharacter.h"

bool MainCharacter::init()
{
    // appeler la méthode init de la superclasse
    if (!Sprite::init())
    {
        return false;
    }

    startingRotation();

    return true;
}

void MainCharacter::startingRotation()
{
    // Load the sprite sheet that contains the frames for the main character animation
    this->spritecache = SpriteFrameCache::getInstance();
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/down/mainCharacter-down.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/up/mainCharacter-up.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/left/mainCharacter-left.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/right/mainCharacter-right.plist");

    this->setSpriteFrame("mainCharacter-down-1.png");
}

Animate* MainCharacter::getLeftWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++) {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-left-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterLeftAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterLeftAnimate = Animate::create(mainCharacterLeftAnimation);

    return mainCharacterLeftAnimate;
}

Animate* MainCharacter::getRightWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-right-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterRightAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterRightAnimate = Animate::create(mainCharacterRightAnimation);

    return mainCharacterRightAnimate;
}

Animate* MainCharacter::getDownWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-down-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterDownAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterDownAnimate = Animate::create(mainCharacterDownAnimation);

    return mainCharacterDownAnimate;
}

Animate* MainCharacter::getUpWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-up-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterUpAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterUpAnimate = Animate::create(mainCharacterUpAnimation);

    return mainCharacterUpAnimate;
}