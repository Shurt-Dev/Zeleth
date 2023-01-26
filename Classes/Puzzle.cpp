#include "Puzzle.h"

bool Puzzle::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}