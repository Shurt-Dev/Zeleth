#include "Attack.h"

bool Attack::init()
{
    if (!Node::init())
    {
        return false;
    }

    createAttackZone();

    createAttackButton();

    button();

    return true;
}

void Attack::createAttackZone()
{
    m_attackZone = Sprite::create("sprites/background/attack_zone.png");

    this->addChild(m_attackZone);
}

void Attack::createAttackButton()
{
    m_attackButton = Button::create("sprites/background/button_attack.png");

    m_attackButton->setPosition(Vec2(0, 0));

    this->addChild(m_attackButton);
}

Sprite* Attack::getAttackZone()
{
    return m_attackZone;
}

Button* Attack::getAttackButton()
{
    return m_attackButton;
}

void Attack::button()
{
    // Ajouter un événement de clic au bouton
    m_attackButton->addClickEventListener([](Ref* sender) {
        // Code à exécuter lorsque le bouton est cliqué
        CCLOG("Le bouton a ete cliqué !");
        });
}