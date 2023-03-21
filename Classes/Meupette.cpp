#include "Meupette.h"

bool Meupette::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    life = 60.0f;
    damage = 10.0f;
    initiative = 50.0f;
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

Action* Meupette::getIdleAnimation()
{
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 12; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("meupette_idle-%d.png", i));
        frames.pushBack(frame);
    }

    idleAnimation = Animation::createWithSpriteFrames(frames, 0.06f);
    idleAnimate = Animate::create(idleAnimation);

    return RepeatForever::create(idleAnimate);
}

Action* Meupette::getAttackAnimation()
{
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 28; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("meupette_attack-%d.png", i));
        frames.pushBack(frame);
    }

    attackAnimation = Animation::createWithSpriteFrames(frames, 0.06f);
    attackAnimate = Animate::create(attackAnimation);

    return attackAnimate;
}