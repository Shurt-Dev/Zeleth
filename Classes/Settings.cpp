#include "Settings.h"

bool Settings::init()
{
    if (!Node::init())
    {
        return false;
    }

    createDeploySettingButton();

    return true;
}

void Settings::createDeploySettingButton()
{
    _deploySettingsButton = DeploySettingsButton::create();

    this->addChild(_deploySettingsButton);
}