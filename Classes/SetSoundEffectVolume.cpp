#include "SetSoundEffectVolume.h"

bool SetSoundEffectVolume::init()
{
    if (!Node::init())
    {
        return false;
    }

    createTextEffects();
    createSliderEffects();

    return true;
}

void SetSoundEffectVolume::createTextEffects()
{
    textSoundEffect = Label::createWithTTF("Sound Effects", "fonts/ui/normal.ttf", 24);

    textSoundEffect->setPosition(Vec2(0, 50));

    this->addChild(textSoundEffect);
}

void SetSoundEffectVolume::createSliderEffects()
{
    // Créer le slider
    slider = Slider::create();

    // Configurer la texture du slider et de la barre de progression

    slider->loadBarTexture("sprites/ui/settings/audio/Slider_Back.png");
    slider->loadProgressBarTexture("sprites/ui/settings/audio/Slider_PressBar.png");
    slider->loadSlidBallTextures
    (
        "sprites/ui/settings/audio/SliderNode_Normal.png",
        "sprites/ui/settings/audio/SliderNode_Press.png",
        "sprites/ui/settings/audio/SliderNode_Disable.png"
    );

    // Configurer la valeur maximale du slider
    slider->setMaxPercent(100);

    // Définir la valeur actuelle du slider (ici, 75% du volume)
    slider->setPercent(75);

    // Ajouter un événement qui sera déclenché lorsque la valeur du slider change
    slider->addEventListener([](Ref* sender, Slider::EventType type) {
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED) {
            auto slider = static_cast<Slider*>(sender);
            int percent = slider->getPercent();
            // Mettre à jour le volume de la musique en fonction de la valeur du slider
            SimpleAudioEngine::getInstance()->setEffectsVolume(percent / 100.0f);
        }
    });

    // Ajouter le slider à la scène
    this->addChild(slider);
}