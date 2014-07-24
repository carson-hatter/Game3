#include "BloodDrop.h"

BloodDrop::BloodDrop(sf::Vector2f Initial_Position)
{
	Sprite.setRadius(12);
	Sprite.setPosition(Initial_Position);
	Sprite.setFillColor(sf::Color::Red);

	expiration_time = 5;
}