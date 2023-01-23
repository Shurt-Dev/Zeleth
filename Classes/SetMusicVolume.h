#include "cocos2d.h"
#include "ui/UIButton.h"
#include "ui/UISlider.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace ui;

class SetMusicVolume : public Node
{
public:
	virtual bool init();

    void createTextMusic();
    void createSliderMusic();

    // Création de l'objet
    CREATE_FUNC(SetMusicVolume);

private:
    Label* textMusic;
    Slider* slider;
};