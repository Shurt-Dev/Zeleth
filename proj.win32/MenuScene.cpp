#include "MenuScene.h"

using namespace CocosDenshion;

Scene* MenuScene::createScene()
{
    // Preload the background music
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/music/menu.ogg");
    // Preload click sound
    SimpleAudioEngine::getInstance()->preloadEffect("sound/sfx/click.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("sound/sfx/click-error.wav");

    return MenuScene::create();
}

bool MenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Determine the center coordinates of the screen
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    // Load the background image
    auto background = Sprite::create("sprites/background/menu.png");

    // Set the anchor point of the background to the bottom-left corner
    background->setAnchorPoint(Vec2(0, 0));

    // Set the scale of the background to fit the screen size
    background->setScale(visibleSize.width / background->getContentSize().width,
        visibleSize.height / background->getContentSize().height);

    // Set the position of the background based on its size and anchor point
    background->setPosition(Vec2(-(background->getContentSize().width * background->getAnchorPoint().x),
        -(background->getContentSize().height * background->getAnchorPoint().y)));

    // Add the background to the scene
    this->addChild(background);

    // Title Game and animation
    auto title = Label::createWithTTF("Zeleth", "fonts/title-game.ttf", 200);
    title->setPosition(Vec2(center.x, origin.y + 3 * visibleSize.height / 4));
    this->addChild(title);

    //Set Audio default
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.4);

    // Play the background music in a loop
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/music/menu.ogg", true);

    // Start
    auto startText = Label::createWithTTF("Start", "fonts/studio.ttf", 50);

    auto start = MenuItemSprite::create(
        Sprite::create("sprites/ui/menu/normal.png"), // normal state
        Sprite::create("sprites/ui/menu/hover.png"), // hover state
        startText, // child node
        CC_CALLBACK_1(MenuScene::onStartClicked, this)); // callback function

    // Set the position of the button start
    start->setPosition(Vec2(0, 0));

    // Set the scale of the start button to 2 times its original size
    start->setScale(2.0f);

    // Settings
    auto settings = MenuItemSprite::create(
        Sprite::create("sprites/ui/menu/normal.png"), // normal state
        Sprite::create("sprites/ui/menu/hover.png"), // hover state
        CC_CALLBACK_1(MenuScene::onSettingsClicked, this)); // callback function

    // Set the position of the button quit
    settings->setPosition(Vec2(0, -200));
    // Set the scale of the start button to 2 times its original size
    settings->setScale(2.0f);


    // Quit
    auto quit = MenuItemSprite::create(
        Sprite::create("sprites/ui/menu/normal.png"), // normal state
        Sprite::create("sprites/ui/menu/hover.png"), // hover state
        CC_CALLBACK_1(MenuScene::onQuitClicked, this)); // callback function

    // Set the position of the button quit
    quit->setPosition(Vec2(0, -400));
    // Set the scale of the start button to 2 times its original size
    quit->setScale(2.0f);

    // Menu Group
    auto menu = Menu::create(start, settings, quit, NULL);

    // Add the menu to the scene
    this->addChild(menu);

    return true;
}

void MenuScene::onStartClicked(Ref* sender)
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");

    // Create the next scene
    auto mapScene = MapScene::createScene();

    // Replace the current scene with the next scene
    Director::getInstance()->replaceScene(TransitionFade::create(2.0f, mapScene));
}


void MenuScene::onSettingsClicked(Ref* sender)
{
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");

    // Handle button 2 click event
}

void MenuScene::onQuitClicked(Ref* sender)
{
    SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");

    Director::getInstance()->end();
}

