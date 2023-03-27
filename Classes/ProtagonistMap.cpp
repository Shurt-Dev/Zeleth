#include "ProtagonistMap.h"

bool ProtagonistMap::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    setScreenPosition();

    createAnimations();

    setKeyboardInput();

    _movementSpeed = 6;

    _isKeyUpPressed = false;
    _isKeyRightPressed = false;
    _isKeyDownPressed = false;
    _isKeyLeftPressed = false;

    return true;
}

void ProtagonistMap::createAnimations()
{
    m_animation = AnimationsProtagonistMap::create();

    m_animation->loadAnimations();
    m_animation->getStartRotation();

    this->addChild(m_animation);
}

void ProtagonistMap::setScreenPosition()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    this->setPosition(center);
}

void ProtagonistMap::setKeyboardInput()
{
    listener = EventListenerKeyboard::create();

    listener->onKeyPressed = CC_CALLBACK_2(ProtagonistMap::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(ProtagonistMap::onKeyReleased, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    this->scheduleUpdate();
}

void ProtagonistMap::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isKeyLeftPressed = true;
        lastMovementDirection = Vec2(-1, 0);
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isKeyRightPressed = true;
        lastMovementDirection = Vec2(1, 0);
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isKeyUpPressed = true;
        lastMovementDirection = Vec2(0, 1);
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isKeyDownPressed = true;
        lastMovementDirection = Vec2(0, -1);
        break;
    default:
        break;

    }
}

void ProtagonistMap::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        _isKeyLeftPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        _isKeyRightPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        _isKeyUpPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        _isKeyDownPressed = false;
        break;
    default:
        break;
    }
}

void ProtagonistMap::update(float delta)
{
    // MOVEMENTS

    movement = Vec2::ZERO;

    if (_isKeyLeftPressed)
    {
        movement.x = -1;
    }
    else if (_isKeyRightPressed)
    {
        movement.x = 1;
    }
    else if (_isKeyUpPressed)
    {
        movement.y = 1;
    }
    else if (_isKeyDownPressed)
    {
        movement.y = -1;
    }

    // s'assurer que movement ne contient qu'une seule valeur non nulle
    if (movement.x != 0 && movement.y != 0)
    {
        movement.x = 0;
    }

    // mettre à jour la position du _tileMap par pixel et à chaque frame
    this->setPosition(this->getPosition() + movement * _movementSpeed);

    // ANIMATIONS

    // Set the animation state based on the movement
    if (movement.x == -1)
    {
        m_animation->setAnimation(AnimationState::Left);
    }
    if (movement.x == 1)
    {
        m_animation->setAnimation(AnimationState::Right);
    }
    if (movement.y == 1)
    {
        m_animation->setAnimation(AnimationState::Up);
    }
    if (movement.y == -1)
    {
        m_animation->setAnimation(AnimationState::Down);
    }

    if (movement.x == 0 && movement.y == 0)
    {
        // Déterminer la direction dans laquelle le personnage ne se déplace plus
        if (lastMovementDirection.x == -1)
        {
            m_animation->setAnimation(AnimationState::IdleLeft);
        }
        if (lastMovementDirection.x == 1)
        {
            m_animation->setAnimation(AnimationState::IdleRight);
        }
        if (lastMovementDirection.y == 1)
        {
            m_animation->setAnimation(AnimationState::IdleUp);
        }
        if (lastMovementDirection.y == -1)
        {
            m_animation->setAnimation(AnimationState::IdleDown);
        }
    }
}