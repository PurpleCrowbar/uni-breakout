#include "AudioManager.h"

// Some initial setup of music.
// All music will loop and have half the normal volume (so background music is quieter).
AudioManager::AudioManager()
{
	music.setLoop(true);
	music.setVolume(40);
    sounds.reserve(8);

    addMusic("sfx/railjet.ogg", "main_theme");

    addSound("sfx/coin.wav", "brick_break");
	addSound("sfx/impact.wav", "impact");
}

AudioManager::~AudioManager()
{
}

// Given a filename and key a new SOUND object is added to the list. Loading the object into memory for playback
void AudioManager::addSound(const std::string& filename, const std::string& lname)
{
	sounds.emplace_back();
	sounds.back().loadSound(filename, lname);
}

// Play back sound based on provided key.
void AudioManager::playSoundbyName(std::string lname)
{
	for (int i = 0; i < sounds.size(); i++)
	{
		if (sounds[i].name == lname)
		{
			sounds[i].sound.play();
			return;
		}
	}
}

// Stop all sounds. Possible that multiple sounds (not music) can be played simultaneously. This stops all sounds.
void AudioManager::stopAllSounds()
{
	for (int i = 0; i < sounds.size(); i++)
	{
		sounds[i].sound.stop();
	}
}

sf::Sound* AudioManager::getSound(const std::string& lname)
{
	for (int i = 0; i < sounds.size(); i++)
	{
		if (sounds[i].name == lname)
		{
			return &sounds[i].sound;
		}
	}
	return nullptr;
}

void AudioManager::playSoundFromOffset(const std::string& lname, const sf::Time& offset, const float& pitch) {
    auto sound = getSound(lname);
    sound->setPitch(pitch);
    sound->play();
    sound->setPlayingOffset(offset);
}

// Stores filename and key of music file. These are not loaded into memory but streamed when required.
void AudioManager::addMusic(std::string filename, std::string lname)
{
	MusicObject mu;
	musics.push_back(mu);
	musics.back().setMusic(filename, lname);
}

// Starts streaming music file based on key provided.
void AudioManager::playMusicbyName(std::string lname)
{
	for (int i = 0; i < musics.size(); i++)
	{
		if (musics[i].name == lname)
		{
			music.openFromFile(musics[i].filename);
			music.play();
			return;
		}
	}
}

// Stops music.
void AudioManager::stopAllMusic()
{
	music.stop();
}

// Returns pointer to music object.
sf::Music* AudioManager::getMusic()
{
	return &music;
}
