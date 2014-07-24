/*
* "BackgroundSFX" generates the mundane background noise the user will hear.
* To be instantiated in Grid class.
*/
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

class BackgroundSFX
{
private: sf::Vector2f Origin;
		 
/*If displacement from Origin to PC is less than 'max_distance, the user will 
hear this sound effect*/
private: float max_distance;

private: float max_volume;

private: float min_volume;

private: sf::Sound SFX;

private: sf::SoundBuffer *SFX_Buffer;

public: BackgroundSFX(sf::Vector2f,//origin
			float, //max_distance
			std::string, //which sound buffer to load
			unsigned int
			);

/*Handles starting/restarting of sound*/
public: void playSFX(sf::Vector2f // PC position
			);

/*Judges what volume should be set too, relative to PC's displacment from 
sound origin*/
private: void volumeControl(float//PC's displacement
						   );

/*Stops sound*/
public: void stopSFX(){SFX.stop();}
};