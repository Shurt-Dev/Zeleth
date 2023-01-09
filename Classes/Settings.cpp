#include "Settings.h"

bool Settings::init()
{
    if (!Node::init())
    {
        return false;
    }

    createDeploySettingButton();
    createSetSoundEffectVolume();
    createSetMusicVolume();

    return true;
}

void Settings::createDeploySettingButton()
{
    _deploySettingsButton = DeploySettingsButton::create();

    _deploySettingsButton->settingsButton->addClickEventListener([&](Ref* sender)
    {
        // sound effect
        _deploySettingsButton->clicEffect();

        if (isActivate)
        {
            _setMusicVolume->setVisible(false);
            _setSoundEffectVolume->setVisible(false);
            isActivate = false;
        }
        else
        {
            _setSoundEffectVolume->setVisible(true);
            _setMusicVolume->setVisible(true);
            isActivate = true;
        }
    });

    this->addChild(_deploySettingsButton);
}

void Settings::createSetSoundEffectVolume()
{
    _setSoundEffectVolume = SetSoundEffectVolume::create();

    _setSoundEffectVolume->setVisible(false);

    _setSoundEffectVolume->setPosition(Vec2(0, 100));

    this->addChild(_setSoundEffectVolume);
}

void Settings::createSetMusicVolume()
{
    _setMusicVolume = SetMusicVolume::create();

    _setMusicVolume->setVisible(false);

    _setMusicVolume->setPosition(Vec2(0, 200));

    this->addChild(_setMusicVolume);
}