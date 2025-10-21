// Sound object
// Loads a sound file and stores related key.
// Key is used to find specific sounds for playback
// @author Paul Robertson

#pragma once
#include "SFML\Audio.hpp"

class SoundObject
{
public:
    SoundObject();
    ~SoundObject();

    // common C++ idiom for classes holding unique pointers. prevents illegal attempts to copy a unique ptr 
    SoundObject(const SoundObject&) = delete; // disable copying by construction
    SoundObject& operator=(const SoundObject&) = delete; // disable copying by assignment
    SoundObject(SoundObject&&) noexcept = default; // enable move construction
    SoundObject& operator=(SoundObject&&) noexcept = default; // enable move assignment

    // Receives filepath and key name, loads sound file and stores alonside key
    void loadSound(const std::string& filename, const std::string& lname);

    // Sound and key variables. (shouldn't be public)
    sf::Sound sound;
    std::string name;
private:
    // Sound buffer must not leave scope or sound will be destroyed.
    std::unique_ptr<sf::SoundBuffer> buffer;
};
