/*
* "BloodSplatter" is the visual representation of blood lost from a character
* being hit by a bullet. Instances only exist for a limited amount of time.
* Instantiated in "Game".
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class BloodSplatter
{
private: std::vector<sf::CircleShape> Mist_Sprites;

public: unsigned int getMistSpritesVectorSize(){return Mist_Sprites.size();}

public: sf::CircleShape getMistSprite(unsigned int i){return Mist_Sprites[i];}

private: sf::CircleShape Circle_Sprite;

public: sf::CircleShape getCircleSprite(){return Circle_Sprite;}

private: sf::ConvexShape Triangle_Sprite;

public: sf::ConvexShape getTriangleSprite(){return Triangle_Sprite;}

/*Constr. uses trigonometry to determine where blood splatter is positioned
and how it is rotated*/
public: BloodSplatter(sf::Vector2f,//victims position
			sf::Vector2f//attackers position
			);

private: sf::Clock Expiration_Clock;

private: unsigned int expiration_time;

public: bool isExpired();
};