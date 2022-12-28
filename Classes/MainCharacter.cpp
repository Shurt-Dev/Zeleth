#include "MainCharacter.h"

bool MainCharacter::init()
{
    // appeler la méthode init de la superclasse
    if (!Sprite::init())
    {
        return false;
    }

    setCenterScreen();

    return true;
}

void MainCharacter::setCenterScreen()
{
    // Récupération de la taille de l'écran visible
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // Calcul de la position du personnage au milieu de l'écran
    Vec2 characterPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2);

    // Définition de la position du personnage
    this->setPosition(characterPosition);
}

Animate* MainCharacter::getLeftWalkAnimation()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites/characters/main/left/mainCharacter-left.plist");

    // Create the sprite and add it to the scene
    auto mainCharacterLeftSprite = Sprite::createWithSpriteFrameName("mainCharacter-left-0.png");
    this->addChild(mainCharacterLeftSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-left-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterLeftAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterLeftAnimate = Animate::create(mainCharacterLeftAnimation);

    // Run the animation forever
    mainCharacterLeftSprite->runAction(RepeatForever::create(mainCharacterLeftAnimate));

    return mainCharacterLeftAnimate;
}

Animate* MainCharacter::getRightWalkAnimation()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites/characters/main/right/mainCharacter-right.plist");

    // Create the sprite and add it to the scene
    auto mainCharacterRightSprite = Sprite::createWithSpriteFrameName("mainCharacter-right-0.png");
    this->addChild(mainCharacterRightSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-right-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterRightAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterRightAnimate = Animate::create(mainCharacterRightAnimation);

    // Run the animation forever
    mainCharacterRightSprite->runAction(RepeatForever::create(mainCharacterRightAnimate));

    return mainCharacterRightAnimate;
}

Animate* MainCharacter::getDownWalkAnimation()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites/characters/main/down/mainCharacter-down.plist");

    // Create the sprite and add it to the scene
    auto mainCharacterDownSprite = Sprite::createWithSpriteFrameName("mainCharacter-down-0.png");
    this->addChild(mainCharacterDownSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-down-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterDownAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterDownAnimate = Animate::create(mainCharacterDownAnimation);

    // Run the animation forever
    mainCharacterDownSprite->runAction(RepeatForever::create(mainCharacterDownAnimate));

    return mainCharacterDownAnimate;
}

Animate* MainCharacter::getUpWalkAnimation()
{
    // Load the sprite sheet that contains the frames for the portal animation
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites/characters/main/up/mainCharacter-up.plist");

    // Create the sprite and add it to the scene
    auto mainCharacterUpSprite = Sprite::createWithSpriteFrameName("mainCharacter-up-0.png");
    this->addChild(mainCharacterUpSprite);

    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-up-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterUpAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterUpAnimate = Animate::create(mainCharacterUpAnimation);

    // Run the animation forever
    mainCharacterUpSprite->runAction(RepeatForever::create(mainCharacterUpAnimate));

    return mainCharacterUpAnimate;
}