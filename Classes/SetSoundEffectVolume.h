#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/UIButton.h"
#include "ui/UISlider.h"

USING_NS_CC;

using namespace ui;
using namespace CocosDenshion;

class SetSoundEffectVolume : public Node
{
public:
	virtual bool init();

	void createTextEffects();
	void createSliderEffects();
	
	// implement the "static create()" method manually
	CREATE_FUNC(SetSoundEffectVolume);

private:
	Label* textSoundEffect;
	Slider* slider;
};