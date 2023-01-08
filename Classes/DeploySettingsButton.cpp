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
    auto settingsButton = ui::Button::create("sprites/ui/menu/settings.png");

    // Disable scaling when the button is clicked
    settingsButton->setZoomScale(0);

    // Set the position of the settings button
    auto visibleSize = Director::getInstance()->getVisibleSize();
    this->setPosition(Vec2(150, 40));

    this->addChild(settingsButton);
}

void DeploySettingsButton::createText()
{
    // Create the label
    auto settingsButtonText = Label::createWithTTF("PARAMETRE", "fonts/ui/normal.ttf", 22);
    settingsButtonText->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    // Position the label within the settings button
    settingsButtonText->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));

    // Add the label to the settings button
    this->addChild(settingsButtonText);
}

void DeploySettingsButton::clicEffect()
{
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");
}