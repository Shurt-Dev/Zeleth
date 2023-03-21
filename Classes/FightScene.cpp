#pragma once
#include "FightScene.h"

Scene* FightScene::createScene()
{
    return FightScene::create();
}

bool FightScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    dataScreenPosition();

    fightLoop();

    return true;
}

void FightScene::dataScreenPosition()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    backgroundPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    actionBarPosition = Vec2(visibleSize.width / 2, visibleSize.height / 2 - 440);
    enemyPosition = Vec2(1300, 750);
    allyPosition = Vec2(0, 0);
}

void FightScene::addBackground()
{
    battleZoneBackground.createBackgroundEuphoria();

    battleZoneBackground.getBackgroundEuphoria()->setPosition(backgroundPosition);

    this->addChild(battleZoneBackground.getBackgroundEuphoria());
}

void FightScene::addActionBar()
{
    m_actionBar = ActionBar::create();

    m_actionBar->setPosition(actionBarPosition);

    this->addChild(m_actionBar);
}

void FightScene::fightLoop()
{
    addBackground();
    addActionBar();

    m_oskar_khas = ProtagonistFight::create();
    m_meupette = Meupette::create();

    // set position
    //m_oskar_khas->setPosition(allyPosition);
    m_meupette->setPosition(enemyPosition);

    this->addChild(m_meupette);
    this->addChild(m_oskar_khas);

    getInitiator();

    //m_iop-> idle anim
    idleActionEnemy = m_meupette->runAction(m_meupette->getIdleAnimation());

    turn = 0;

    while (m_oskar_khas->isAlive() && m_meupette->isAlive())
    {
        switch (turn)
        {
        // Who start
        case 0:
            if (playerInitiator)
            {
                turn = 1;
            }
            if (!playerInitiator)
            {
                turn = 2;
            }
            break;

        // tour joueur
        case 1:

            //m_oskar_khas->attack(m_meupette);

            turn = 2;
            break;

        // tour IA
        case 2:
            // animation
            //m_meupette->stopAction(idleActionEnemy);
            m_meupette->runAction(m_meupette->getIdleAnimation());
            //m_meupette->stopAction(idleActionEnemy);
            //m_meupette->runAction(m_meupette->getAttackAnimation());

            // txt
            m_meupette->attack(m_oskar_khas);

            turn = 1;
            break;
        }
    }

    m_meupette->stopAction(idleActionEnemy);
}

void FightScene::getInitiator()
{
    playerInitiator = false;

    if (m_meupette->Initiative() < m_oskar_khas->Initiative())
    {
        playerInitiator = true;
    }
    else if (m_meupette->Initiative() > m_oskar_khas->Initiative())
    {
        playerInitiator = false;
    }
    else
    {
        // Initialisation de la graine pour la fonction rand()
        std::srand(std::time(nullptr));

        // G�n�ration d'un nombre al�atoire entre 0 et 1
        bool choix = std::rand() % 2 == 0;

        // Affichage du choix al�atoire
        if (choix) {
            playerInitiator = false;
        }
        else {
            playerInitiator = true;
        }
    }
}