#include "cocos2d.h"

#include "SetMusicVolume.h"
#include "SetSoundEffectVolume.h"
#include "DeploySettingsButton.h"

USING_NS_CC;

class Settings : public Node
{
public:
	virtual bool init();

	void createDeploySettingButton();

	CREATE_FUNC(Settings);

private:
	DeploySettingsButton* _deploySettingsButton;
};