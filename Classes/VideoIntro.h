#include "cocos2d.h"

USING_NS_CC;

using namespace ui;

class VideoIntro : public Node
{
public:
	virtual bool init();

	void createVideo();

	// implement the "static create()" method manually
	CREATE_FUNC(VideoIntro);

private:
	VideoPlayer* videoPlayer;
};