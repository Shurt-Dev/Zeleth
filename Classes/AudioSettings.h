#include "cocos2d.h"
#include "ui/UIButton.h"

#include "SetMusicVolume.h"
#include "SetSoundEffectVolume.h"

USING_NS_CC;

class AudioSettings : public Node
{
public:
	virtual bool init();

	void createSettingsButton();

	void addAudioButtons();
	void revealAudioButtons();

	CREATE_FUNC(AudioSettings);

private:
	Button* settingsButton;
	Label* settingsButtonText;

	SetMusicVolume* setMusicVolume;
	SetSoundEffectVolume* setSoundEffectVolume;
};
