#include "Meupette.h"

bool Meupette::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    life = 60.0f;
    damage = 10.0f;
    name = "Meupette";

    loadAnimation();

    this->setSpriteFrame("meupette_idle-1.png");

    return true;
}

void Meupette::loadAnimation()
{
    this->spritecache = SpriteFrameCache::getInstance();

    this->spritecache->addSpriteFramesWithFile("sprites/entities/monsters/meupette/idle/meupette_idle.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/entities/monsters/meupette/attack/meupette_attack.plist");
}

void Meupette::getIdleAnimation()
{
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 12; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("meupette_idle-%d.png", i));
        frames.pushBack(frame);
    }

    Animation* idleAnimation = Animation::createWithSpriteFrames(frames, 0.06f);
    Animate* idleAnimate = Animate::create(idleAnimation);

    RepeatForever::create(idleAnimate);

    this->runAction(RepeatForever::create(idleAnimate));
}

void Meupette::getAttackAnimation()
{
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 28; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("meupette_attack-%d.png", i));
        frames.pushBack(frame);
    }

    attackAnimation = Animation::createWithSpriteFrames(frames, 0.06f);
    attackAnimate = Animate::create(attackAnimation);

    this->runAction(attackAnimate);
}