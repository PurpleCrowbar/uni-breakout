#include "SoundObject.h"

SoundObject::SoundObject()
{
    buffer = nullptr;
}

SoundObject::~SoundObject() = default;

// Loads sound into memory and can be identified by key (name).
// Receives filepath and key name, loads sound file and stores alongside key
void SoundObject::loadSound(const std::string& filename, const std::string& lname)
{
    buffer = std::make_unique<sf::SoundBuffer>();
    buffer->loadFromFile(filename);
    sound.setBuffer(*buffer);
    name = lname;
}
