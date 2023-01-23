#include "AudioSettings.h"

bool AudioSettings::init()
{
    if (!Node::init())
    {
        return false;
    }

    createSettingsButton();

    addAudioButtons();
    revealAudioButtons();

    return true;
}

void AudioSettings::createSettingsButton()
{
    // create button
    settingsButton = Button::create("sprites/ui/menu/settings.png");

    // add to the parent
    this->addChild(settingsButton);

    // Create the text button
    settingsButtonText = Label::createWithTTF("PARAMETRE", "fonts/ui/normal.ttf", 22);
    // set color white
    settingsButtonText->setColor(Color3B(229, 229, 229));

    // Position the label within the settings button
    settingsButtonText->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));

    // Add the label to the settings button
    this->addChild(settingsButtonText);
}

void AudioSettings::addAudioButtons()
{
    // music button
    setMusicVolume = SetMusicVolume::create();

    setMusicVolume->setPosition(Vec2(0, 75));

    this->addChild(setMusicVolume);

    setMusicVolume->setVisible(false);

    // sound effect button
    setSoundEffectVolume = SetSoundEffectVolume::create();

    setSoundEffectVolume->setPosition(Vec2(0, 175));

    this->addChild(setSoundEffectVolume);

    setSoundEffectVolume->setVisible(false);
}

void AudioSettings::revealAudioButtons()
{
    // music state
    settingsButton->addClickEventListener([&](Ref* sender)
    {
        // clic effect
        SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");
        // reveal or hide
        setMusicVolume->setVisible(!setMusicVolume->isVisible());
        setSoundEffectVolume->setVisible(!setSoundEffectVolume->isVisible());
    });
}