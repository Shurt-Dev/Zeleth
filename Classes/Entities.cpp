#include "Entities.h"

bool Entities::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void Entities::createProtagonist()
{
    m_protagonist = Protagonist::create();
}

Protagonist* Entities::setProtagonist()
{
    return m_protagonist;
}