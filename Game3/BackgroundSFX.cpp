#include "BackgroundSFX.h"

BackgroundSFX::BackgroundSFX(sf::Vector2f Origin_, float max_distance_, std::string Which_Sound, unsigned int max_volume_)
{
	Origin = Origin_;

	max_distance = max_distance_;

	SFX_Buffer = new sf::SoundBuffer;
	
	if(Which_Sound == "diner")
	{
		SFX_Buffer->loadFromFile("diner_sound.wav");
	}
	if(Which_Sound == "auto repair shop")
	{
		SFX_Buffer->loadFromFile("auto_repair_shop_sfx.wav");
	}
	if(Which_Sound == "grocery store")
	{
		SFX_Buffer->loadFromFile("grocery_store_sfx.wav");
	}
	if(Which_Sound == "bar")
	{
		SFX_Buffer->loadFromFile("bar.wav");
	}

	SFX.setBuffer(*SFX_Buffer);

	max_volume = max_volume_;
	min_volume = 0;
}

void BackgroundSFX::playSFX(sf::Vector2f P_C_Position)
{
	float distance, x_diff, y_diff;
	x_diff = P_C_Position.x - Origin.x;
	y_diff = P_C_Position.y - Origin.y;
	distance = sqrt((x_diff * x_diff) + (y_diff * y_diff));

	if(distance < max_distance)
	{	
		if(SFX.getStatus() != sf::Sound::Playing)
		{
			SFX.play();
		}

		volumeControl(distance);
	}
}

void BackgroundSFX::volumeControl(float pcs_displacement)
{
	float distance_as_percengtage = 1 - (pcs_displacement / max_distance);

	SFX.setVolume((distance_as_percengtage * (max_volume - min_volume)) + min_volume);
}