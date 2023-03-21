#include "AnimationsProtagonistMap.h"

bool AnimationsProtagonistMap::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}

void AnimationsProtagonistMap::loadAnimations()
{
    // Load the sprite sheet that contains the frames for the main character animation
    this->spritecache = SpriteFrameCache::getInstance();
    this->spritecache->addSpriteFramesWithFile("sprites/entities/protagonist/down/mainCharacter-down.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/entities/protagonist/up/mainCharacter-up.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/entities/protagonist/left/mainCharacter-left.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/entities/protagonist/right/mainCharacter-right.plist");
}

void AnimationsProtagonistMap::getStartRotation()
{
    this->setSpriteFrame("mainCharacter-down-1.png");
}

void AnimationsProtagonistMap::getLeftWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++) {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-left-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterLeftAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterLeftAnimate = Animate::create(mainCharacterLeftAnimation);

    this->runAction(RepeatForever::create(mainCharacterLeftAnimate));
}

void AnimationsProtagonistMap::getRightWalkAnimation()
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

    this->runAction(RepeatForever::create(mainCharacterRightAnimate));
}

void AnimationsProtagonistMap::getDownWalkAnimation()
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

    this->runAction(RepeatForever::create(mainCharacterDownAnimate));
}

void AnimationsProtagonistMap::getUpWalkAnimation()
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

    this->runAction(RepeatForever::create(mainCharacterUpAnimate));
}

void AnimationsProtagonistMap::getIdleLeft()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-left-1.png");
}

void AnimationsProtagonistMap::getIdleRight()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-right-1.png");
}

void AnimationsProtagonistMap::getIdleUp()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-up-1.png");
}

void AnimationsProtagonistMap::getIdleDown()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-down-1.png");
}

void AnimationsProtagonistMap::setAnimationState(AnimationState state)
{
    _animationState = state;
}

void AnimationsProtagonistMap::setAnimation(AnimationState state)
{
    // Si l'animation en cours d'exécution est la même que celle demandée, ne rien faire
    if (_animationState == state) return;

    // Mettre à jour l'état de l'animation
    _animationState = state;

    // Arrêter toutes les actions en cours d'exécution
    this->stopAllActions();

    // Sélectionner l'animation à exécuter en fonction de l'état de l'animation
    switch (_animationState)
    {
    case AnimationState::Right:
        getRightWalkAnimation();
        break;
    case AnimationState::Left:
        getLeftWalkAnimation();
        break;
    case AnimationState::Down:
        getDownWalkAnimation();
        break;
    case AnimationState::Up:
        getUpWalkAnimation();
        break;
    case AnimationState::IdleRight:
        getIdleRight();
        break;
    case AnimationState::IdleLeft:
        getIdleLeft();
        break;
    case AnimationState::IdleUp:
        getIdleUp();
        break;
    case AnimationState::IdleDown:
        getIdleDown();
        break;
    }
}
