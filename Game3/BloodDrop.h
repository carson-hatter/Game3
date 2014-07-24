/*
* "BloodDrop" represents blood droplets that fall from an injured 
* user (if PC::is_bleeding). Instances only exist for a limited amount of time.
* Instantiated in BloodTrail.
*/
#pragma once

#include <SFML/Graphics.hpp>

class BloodDrop
{
private: sf::CircleShape Sprite;

public: sf::CircleShape getSprite(){return Sprite;}

private: sf::Clock Expiration_Clock;

private: unsigned int expiration_time;

/*Determines if instantiation took place longer ago than 'expiration_time'; if
true, the given instance will be remove from BloodTrail::Blood_Drops.*/
public: bool isExpired(){if(Expiration_Clock.getElapsedTime().asSeconds() >= expiration_time){return true;}return false;}

public: BloodDrop(sf::Vector2f//location of sprite
			);
};