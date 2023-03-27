#include "Collisions.h"

bool Collisions::init()
{
    AnimationsProtagonistMap animProMap;

    if (!Node::init())
    {
        return false;
    }

    cocos2d::PhysicsBody* playerBody = PhysicsBody::createBox(animProMap.playerSprite->getContentSize());
    animProMap.playerSprite->setPhysicsBody(playerBody);

    return true;
}

void Collisions::CollisionDetection()
{

    // Set up collision detection between the sprite and the collision layer
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [](PhysicsContact& contact) {

        AnimationsProtagonistMap animProMap;

        auto bodyA = contact.getShapeA()->getBody();
        auto bodyB = contact.getShapeB()->getBody();

        // Check if bodyA is the sprite's physics body and bodyB is a solid tile's physics body
        if (bodyA->getNode() == animProMap.playerSprite && bodyB->getNode()->getTag() == 2) {
            // Move the sprite back to its previous position to prevent the collision
            animProMap.playerSprite->setPosition(animProMap.playerSprite->getPreviousPosition());
        }

        // Check if bodyB is the sprite's physics body and bodyA is a solid tile's physics body
        if (bodyB->getNode() == animProMap.playerSprite && bodyA->getNode()->getTag() == 2) {
            // Move the sprite back to its previous position to prevent the collision
            animProMap.playerSprite->setPosition(animProMap.playerSprite->getPreviousPosition());
        }

        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}
