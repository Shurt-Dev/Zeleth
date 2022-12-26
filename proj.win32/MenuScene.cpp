#include "MenuScene.h"
#include "ui/CocosGUI.h"

using namespace CocosDenshion;

Scene* MenuScene::createScene()
{
    // Preload the background music
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/music/menu.ogg");
    // Preload click sound
    SimpleAudioEngine::getInstance()->preloadEffect("sound/sfx/start.mp3");
    SimpleAudioEngine::getInstance()->preloadEffect("sound/sfx/click.mp3");

    return MenuScene::create();
}

bool MenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    // Determine the center coordinates of the screen
    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    _center = Vec2(_origin.x + _visibleSize.width / 2, _origin.y + _visibleSize.height / 2);
    _bottomRight = _origin + Vec2(_visibleSize.width, 0);

    setupBackground();
    setupAudio();
    createTitle();
    setupQuitButton();
    setupStartButton();
    setupSettingsButton();

    return true;
}

void MenuScene::createTitle()
{
    // Title Game and animation
    auto title = Label::createWithTTF("Zeleth", "fonts/title-game.ttf", 250);

    title->setPosition(Vec2(_center.x, _origin.y + 3 * _visibleSize.height / 4));
    title->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    this->addChild(title);
}

void MenuScene::setupAudio()
{
    //Set Audio default
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.4);

    // Play the background music in a loop
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/music/menu.ogg", true);
}

void MenuScene::setupBackground()
{
    // Load the background image
    auto background = Sprite::create("sprites/background/menu.png");

    // Set the anchor point of the background to the bottom-left corner
    background->setAnchorPoint(Vec2(0, 0));

    // Set the scale of the background to fit the screen size
    background->setScale(_visibleSize.width / background->getContentSize().width,
        _visibleSize.height / background->getContentSize().height);

    // Set the position of the background based on its size and anchor point
    background->setPosition(Vec2(-(background->getContentSize().width * background->getAnchorPoint().x),
        -(background->getContentSize().height * background->getAnchorPoint().y)));

    // Add the background to the scene
    this->addChild(background);
}

void MenuScene::setupQuitButton()
{
    // Create the quit button
    auto quitButton = ui::Button::create("sprites/ui/menu/quit.png");

    // Disable scaling when the button is clicked
    quitButton->setZoomScale(0);

    // Set the position of the quit button
    quitButton->setPosition(_bottomRight - Vec2(60, -50));

    // Disable scaling when the button is clicked
    quitButton->setZoomScale(0);

    // Add a callback function to the quit button
    quitButton->addClickEventListener([](Ref* sender) {
        // Quit the game
        Director::getInstance()->end();
        });

    // Add the quit button to the scene
    this->addChild(quitButton);
}

void MenuScene::setupStartButton()
{
    // Create the start button
    auto startButton = ui::Button::create("sprites/ui/menu/start.png");

    // Set the position of the start button
    startButton->setPosition(_center);

    // Disable scaling when the button is clicked
    startButton->setZoomScale(0);

    // Add a callback function to the start button that will change the scene when the button is clicked
    startButton->addClickEventListener([](Ref* sender) {
        // Stop the background music
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();

        // Play the sound
        SimpleAudioEngine::getInstance()->playEffect("sound/sfx/start.mp3");

        auto mapScene = MapScene::createScene();

        // Change the scene
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, mapScene, Color3B(255, 255, 255)));
        });

    // Create the label
    auto startButtonText = Label::createWithTTF("COMMENCER", "fonts/ui/normal.ttf", 40);
    startButtonText->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    // Add the label to the start button
    startButton->addChild(startButtonText);

    // Position the label within the start button
    startButtonText->setPosition(Vec2(startButton->getContentSize().width / 2, startButton->getContentSize().height / 2));

    // Add the start button to the scene
    this->addChild(startButton);
}

void MenuScene::setupSettingsButton()
{
    // Create the settings button
    auto settingsButton = ui::Button::create("sprites/ui/menu/settings.png");

    // Disable scaling when the button is clicked
    settingsButton->setZoomScale(0);

    // Set the position of the settings button
    auto visibleSize = Director::getInstance()->getVisibleSize();
    settingsButton->setPosition(Vec2(150, 40));

    // Add a callback function to the settings button that will change the scene when the button is clicked
    settingsButton->addClickEventListener([](Ref* sender)
    {
        // Play the sound
        SimpleAudioEngine::getInstance()->playEffect("sound/sfx/click.mp3");

        // display audio settings 
    });

    // Create the label
    auto settingsButtonText = Label::createWithTTF("PARAMETRE", "fonts/ui/normal.ttf", 22);
    settingsButtonText->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    // Add the label to the settings button
    settingsButton->addChild(settingsButtonText);

    // Position the label within the settings button
    settingsButtonText->setPosition(Vec2(settingsButton->getContentSize().width / 2, settingsButton->getContentSize().height / 2));

    // Add the settings button to the scene
    this->addChild(settingsButton);
}