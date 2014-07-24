#include "HUD.h"

void HUD::updateHUD(float health_percentage, float ammo_percentage, float stitching_percentage, float reloading_percentage)
{
	if(health_percentage > 1)
	{
		health_percentage = 1;
	}
	if(health_percentage < 0)
	{
		health_percentage = 0;
	}
	if(ammo_percentage > 1)
	{
		ammo_percentage = 1;
	}
	if(ammo_percentage < 0)
	{
		ammo_percentage = 0;
	}
	
	Health_Sprite.setFillColor(sf::Color((255 - (255 * health_percentage)),(255 * health_percentage), 0, 255));
	Gun_Sprite.setFillColor(sf::Color((255 - (255 * ammo_percentage)),(255 * ammo_percentage), 0, 255));

	if(stitching_percentage <= 1)
	{
		if(!Stitching_Progress_Bar)
		{
			Stitching_Progress_Bar = new sf::RectangleShape;
			Stitching_Progress_Bar->setFillColor(sf::Color(0,0,255,128));
		}

		Stitching_Progress_Bar->setPosition(Health_Sprite.getPosition().x, Health_Sprite.getPosition().y);
		Stitching_Progress_Bar->setSize(sf::Vector2f(Health_Sprite.getSize().x, Health_Sprite.getSize().y * stitching_percentage));
		
	}
	else
	{
		if(Stitching_Progress_Bar)
		{
			delete Stitching_Progress_Bar;
			Stitching_Progress_Bar = NULL;
		}
	}

	if(reloading_percentage <= 1)
	{
		if(!Reloading_Progress_Bar)
		{
			Reloading_Progress_Bar = new sf::RectangleShape;
			Reloading_Progress_Bar->setFillColor(sf::Color(0,0,255,128));
		}
		
		Reloading_Progress_Bar->setPosition(Gun_Sprite.getPosition().x, Gun_Sprite.getPosition().y);
		Reloading_Progress_Bar->setSize(sf::Vector2f(Gun_Sprite.getSize().x, Gun_Sprite.getSize().y * reloading_percentage));
	}
	else
	{
		if(Reloading_Progress_Bar)
		{
			delete Reloading_Progress_Bar;
			Reloading_Progress_Bar = NULL;
		}
	}
}

HUD::HUD()
{
	Health_Sprite_Texture = new sf::Texture;
	Gun_Sprite_Texture = new sf::Texture;
	Health_Sprite_Texture->loadFromFile("health_sprite.jpg");
	Gun_Sprite_Texture->loadFromFile("gun_sprite.jpg");
	Health_Sprite.setTexture(Health_Sprite_Texture);
	Gun_Sprite.setTexture(Gun_Sprite_Texture);
	Health_Sprite.setTextureRect(sf::IntRect(0,0,100,100));
	Gun_Sprite.setTextureRect(sf::IntRect(0,12,100,100));
	Health_Sprite.setSize(sf::Vector2f(100,100));
	Gun_Sprite.setSize(sf::Vector2f(100,100));
	Health_Sprite.setPosition(0, 900 - Health_Sprite.getSize().y);
	Gun_Sprite.setPosition(1600 - Gun_Sprite.getSize().x, 900 - Gun_Sprite.getSize().y);
	Health_Sprite.setFillColor(sf::Color(0, 255, 0, 100));
	Gun_Sprite.setFillColor(sf::Color(0, 255, 0 , 100));

	Stitching_Progress_Bar = NULL;
	Reloading_Progress_Bar = NULL;
}