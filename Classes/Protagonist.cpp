#include "Protagonist.h"

bool Protagonist::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    loadSpriteCache();
    setUpScreenPosition();
    startingRotation();

    return true;
}

void Protagonist::loadSpriteCache()
{
    this->m_spritecache = SpriteFrameCache::getInstance();

    this->m_spritecache->addSpriteFramesWithFile("sprites/characters/main/down/mainCharacter-down.plist");
    this->m_spritecache->addSpriteFramesWithFile("sprites/characters/main/up/mainCharacter-up.plist");
    this->m_spritecache->addSpriteFramesWithFile("sprites/characters/main/left/mainCharacter-left.plist");
    this->m_spritecache->addSpriteFramesWithFile("sprites/characters/main/right/mainCharacter-right.plist");
}

void Protagonist::setUpScreenPosition()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    visibleOrigin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 2);

    this->setPosition(center);
}

void Protagonist::startingRotation()
{
    this->setSpriteFrame("mainCharacter-down-1.png");
}

const float Protagonist::getMovementSpeed()
{
    movementSpeed = 3.0f;

    return movementSpeed;
}

void Protagonist::getLeftWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++) {
        auto frame = m_spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-left-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterLeftAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterLeftAnimate = Animate::create(mainCharacterLeftAnimation);

    this->runAction(RepeatForever::create(mainCharacterLeftAnimate));
}

void Protagonist::getRightWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = m_spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-right-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterRightAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterRightAnimate = Animate::create(mainCharacterRightAnimation);

    this->runAction(RepeatForever::create(mainCharacterRightAnimate));
}

void Protagonist::getDownWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = m_spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-down-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterDownAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterDownAnimate = Animate::create(mainCharacterDownAnimation);

    this->runAction(RepeatForever::create(mainCharacterDownAnimate));
}

void Protagonist::getUpWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = m_spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-up-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterUpAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterUpAnimate = Animate::create(mainCharacterUpAnimation);

    this->runAction(RepeatForever::create(mainCharacterUpAnimate));
}

void Protagonist::getIdleLeft()
{
    this->setSpriteFrame("mainCharacter-left-1.png");
}

void Protagonist::getIdleRight()
{
    this->setSpriteFrame("mainCharacter-right-1.png");
}

void Protagonist::getIdleUp()
{
    this->setSpriteFrame("mainCharacter-up-1.png");
}

void Protagonist::getIdleDown()
{
    this->setSpriteFrame("mainCharacter-down-1.png");
}

void Protagonist::setAnimationState(AnimationState state)
{
    animationState = state;
}

void Protagonist::setAnimation(AnimationState state)
{
    // Si l'animation en cours d'exécution est la même que celle demandée, ne rien faire
    if (animationState == state) return;

    // Mettre à jour l'état de l'animation
    animationState = state;

    // Arrêter toutes les actions en cours d'exécution
    this->stopAllActions();

    // Sélectionner l'animation à exécuter en fonction de l'état de l'animation
    switch (animationState)
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