#include "MenuScene.h"

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
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
    bottomRight = origin + Vec2(visibleSize.width, 0);

    setupBackground();
    setupAudio();
    createTitle();
    setupQuitButton();
    setupStartButton();
    setupAudioSettings();

    return true;
}

void MenuScene::createTitle()
{
    // Title Game and animation
    auto title = Label::createWithTTF("Zeleth", "fonts/title-game.ttf", 250);

    title->setPosition(Vec2(center.x, origin.y + 3 * visibleSize.height / 4));
    title->setColor(Color3B(229, 229, 229)); // couleur blanc (RGB)

    this->addChild(title);
}

void MenuScene::setupAudio()
{
    //Set Audio default
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.4f);

    // Play the background music in a loop
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/music/menu.ogg", true);
}

void MenuScene::setupBackground()
{
    // Load the background image
    background = Sprite::create("sprites/background/menu.png");

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
}

void MenuScene::setupQuitButton()
{
    // Create the quit button
    quitButton = Button::create("sprites/ui/menu/quit.png");

    // Disable scaling when the button is clicked
    quitButton->setZoomScale(0);

    // Set the position of the quit button
    quitButton->setPosition(bottomRight - Vec2(60, -50));

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
    startButton = Button::create("sprites/ui/menu/start.png");

    // Set the position of the start button
    startButton->setPosition(center);

    // Disable scaling when the button is clicked
    startButton->setZoomScale(0);

    // Add a callback function to the start button that will change the scene when the button is clicked
    startButton->addClickEventListener([](Ref* sender) {
        // Stop the background music
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();

        // Play the sound
        SimpleAudioEngine::getInstance()->playEffect("sound/sfx/start.mp3");

        auto gameScene = GameScene::createScene();

        // Change the scene
        Director::getInstance()->replaceScene(TransitionFade::create(1.0, gameScene, Color3B(255, 255, 255)));
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

void MenuScene::setupAudioSettings()
{
    audioSettings = AudioSettings::create();

    audioSettings->setPosition(Vec2(150, 40));

    this->addChild(audioSettings);
}