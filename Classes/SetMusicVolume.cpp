#include "SetMusicVolume.h"

bool SetMusicVolume::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}