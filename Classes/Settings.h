#include "cocos2d.h"
#include "ui/UIButton.h"

#include "SetMusicVolume.h"
#include "SetSoundEffectVolume.h"
#include "DeploySettingsButton.h"

USING_NS_CC;

using namespace ui;

class Settings : public Node
{
public:
	virtual bool init();

	void createDeploySettingButton();
	void createSetMusicVolume();
	void createSetSoundEffectVolume();

	CREATE_FUNC(Settings);

private:
	DeploySettingsButton* _deploySettingsButton;
	SetSoundEffectVolume* _setSoundEffectVolume;
	SetMusicVolume* _setMusicVolume;
	Button* settingsButton;

	bool isActivate = false;
};