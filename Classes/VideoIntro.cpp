#include "VideoIntro.h"

bool VideoIntro::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void VideoIntro::createVideo()
{
    auto videoPlayer = cocos2d::ui::VideoPlayer::create();

    // Chargez la vidéo en utilisant le chemin du fichier
    videoPlayer->setFileName("video/IntroZeleth.mp4");

    // Ajout de l'objet VideoPlayer à la scène
    addChild(videoPlayer);

    // Démarrage de la lecture de la vidéo
    videoPlayer->play();

    // Activez le mode plein écran
    videoPlayer->setFullScreenEnabled(true);
}