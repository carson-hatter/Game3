/*
* "HUD" gives user data regarding PC::health and PC::bullets_in_clip
* through simple sprite shaded from red to green, relative to how much
* health/ammo PC has.
* Instantiated in "Game".
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class HUD
{
private: sf::RectangleShape Health_Sprite;

private: sf::Texture *Health_Sprite_Texture;

private: sf::RectangleShape *Stitching_Progress_Bar;

private: sf::RectangleShape Gun_Sprite;

private: sf::Texture *Gun_Sprite_Texture;

private: sf::RectangleShape *Reloading_Progress_Bar;

public: HUD();

public: void updateHUD(float,//health percentage
			float,//ammo percentage
			float,//stitching progress percentage
			float//reloading progress percentage
			);

public: sf::RectangleShape getHealthSprite(){return Health_Sprite;}

public: sf::RectangleShape getGunSprite(){return Gun_Sprite;}

public: sf::RectangleShape getStitchingProgressBar(){if(Stitching_Progress_Bar){return *Stitching_Progress_Bar;}return sf::RectangleShape();}

public: sf::RectangleShape getReloadingProgressBar(){if(Reloading_Progress_Bar){return *Reloading_Progress_Bar;}return sf::RectangleShape();}
};