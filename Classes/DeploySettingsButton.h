#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

class DeploySettingsButton : public Node
{
public:
	virtual bool init();

	void createButton();
	void createText();
	void clicEffect();

	// implement the "static create()" method manually
	CREATE_FUNC(DeploySettingsButton);
};