#include "GameScene.h"

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // set key state
    isKeyUpPressed = false;
    isKeyRightPressed = false;
    isKeyDownPressed = false;
    isKeyLeftPressed = false;

    initMap();

    setupKeyboardInput();

    mapLoop();

    return true;
}

void GameScene::getIsland()
{
    m_island = Island::create();

    this->addChild(m_island);
}

void GameScene::getProtagonist()
{
    m_protagonist = Protagonist::create();

    this->addChild(m_protagonist);
}

void GameScene::initMap()
{
    getIsland();
    getProtagonist();
}

// keyboard inputs
void GameScene::setupKeyboardInput()
{
    // keys
    m_listener = EventListenerKeyboard::create();
    m_listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    m_listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_listener, this);

    this->scheduleUpdate();
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        isKeyLeftPressed = true;
        lastMovementDirection = Vec2(1, 0);
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        isKeyRightPressed = true;
        lastMovementDirection = Vec2(-1, 0);
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        isKeyUpPressed = true;
        lastMovementDirection = Vec2(0, -1);
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        isKeyDownPressed = true;
        lastMovementDirection = Vec2(0, 1);
        break;
    default:
        break;
    }
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        isKeyLeftPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        isKeyRightPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        isKeyUpPressed = false;
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        isKeyDownPressed = false;
        break;
    default:
        break;
    }
}

void GameScene::update(float delta)
{
    movement = Vec2::ZERO;

    if (isKeyLeftPressed)
    {
        movement.x = 1;
    }
    if (isKeyRightPressed)
    {
        movement.x = -1;
    }
    if (isKeyUpPressed)
    {
        movement.y = -1;
    }
    if (isKeyDownPressed)
    {
        movement.y = 1;
    }

    // s'assurer que movement ne contient qu'une seule valeur non nulle
    if (movement.x != 0 && movement.y != 0)
    {
        movement.x = 0;
    }

    // mettre à jour la position du m_island par pixel et à chaque frame
    m_island->setPosition(m_island->getPosition() + movement * m_protagonist->getMovementSpeed());

    // Set the animation state based on the movement
    if (movement.x == 1)
    {
        m_protagonist->setAnimation(AnimationState::Left);
    }
    if (movement.x == -1)
    {
        m_protagonist->setAnimation(AnimationState::Right);
    }
    if (movement.y == -1)
    {
        m_protagonist->setAnimation(AnimationState::Up);
    }
    if (movement.y == 1)
    {
        m_protagonist->setAnimation(AnimationState::Down);
    }

    if (movement.x == 0 && movement.y == 0)
    {
        // Déterminer la direction dans laquelle le personnage ne se déplace plus
        if (lastMovementDirection.x == 1)
        {
            m_protagonist->setAnimation(AnimationState::IdleLeft);
        }
        if (lastMovementDirection.x == -1)
        {
            m_protagonist->setAnimation(AnimationState::IdleRight);
        }
        if (lastMovementDirection.y == -1)
        {
            m_protagonist->setAnimation(AnimationState::IdleUp);
        }
        if (lastMovementDirection.y == 1)
        {
            m_protagonist->setAnimation(AnimationState::IdleDown);
        }
    }
}

void GameScene::mapLoop()
{
    /* Game Loop */

    /* Island */

    /* Island */
}