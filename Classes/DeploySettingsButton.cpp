#include "DeploySettingsButton.h"

bool DeploySettingsButton::init()
{
    if (!Node::init())
    {
        return false;
    }

    createButton();
    createText();

    return true;
}

void DeploySettingsButton::createButton()
{
    // Create the settings button
    settingsButton = Button::create("sprites/ui/menu/settings.png");

    this->addChild(settingsButton);
}

void DeploySettingsButton::clicEffect()
{
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");
}

void DeploySettingsButton::createText()
{
    // Create the label
    settingsButtonText = Label::createWithTTF("PARAMETRE", "fonts/ui/normal.ttf", 22);
    settingsButtonText->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    // Position the label within the settings button
    settingsButtonText->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));

    // Add the label to the settings button
    this->addChild(settingsButtonText);
}