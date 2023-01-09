#include "cocos2d.h"
#include "ui/UIButton.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace ui;

class DeploySettingsButton : public Node
{
public:
	virtual bool init();

	void createButton();
	void createText();
	void clicEffect();

	Button* settingsButton;

	// implement the "static create()" method manually
	CREATE_FUNC(DeploySettingsButton);

private:
	Label* settingsButtonText;

	bool _isActivate;
	bool _isVisible;
};