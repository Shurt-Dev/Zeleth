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

    m_iop = ProtagonistFight::create();
    m_meupette = Meupette::create();

    // set position
    //m_iop->setPosition(allyPosition);
    m_meupette->setPosition(enemyPosition);

    this->addChild(m_meupette);
    this->addChild(m_iop);

    //m_iop-> idle anim
    idleActionEnemy = m_meupette->runAction(m_meupette->getIdleAnimation());

    getInitiator();

    turn = 0;

    while (m_iop->isAlive() && m_meupette->isAlive())
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
            // txt
            m_iop->attack(m_meupette);

            // animation

            // txt
            m_iop->attack(m_meupette);

            turn = 2;
            break;

        // tour IA
        case 2:

            // animation
            //m_meupette->stopAction(idleActionEnemy);
            //m_meupette->runAction(m_meupette->getAttackAnimation());

            // txt
            m_meupette->attack(m_iop);

            turn = 1;
            break;
        }
    }
}

void FightScene::getInitiator()
{
    playerInitiator = false;

    if (m_meupette->Initiative() < m_iop->Initiative())
    {
        playerInitiator = true;
    }
    else if (m_meupette->Initiative() > m_iop->Initiative())
    {
        playerInitiator = false;
    }
    else
    {
        // Initialisation de la graine pour la fonction rand()
        std::srand(std::time(nullptr));

        // Génération d'un nombre aléatoire entre 0 et 1
        bool choix = std::rand() % 2 == 0;

        // Affichage du choix aléatoire
        if (choix) {
            playerInitiator = false;
        }
        else {
            playerInitiator = true;
        }
    }
}