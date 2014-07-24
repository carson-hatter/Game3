/*
* "PC" is a child class of "Character". This class gives user a Character
* to manipulate: moving it around, rotating it, firing/reloading its weapon and
* stitching up if bleeding.
*/
#pragma once

#include "Character.h"
#include "Grid.h"

class PC : public Character
{
public: PC(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Sprite_Sheet, sf::Vector2f Initial_Position, Grid &Initial_Grid, sf::Vector2i Map_Dimensions_) : Character(Body_Sprite_Texture_Rect, Sprite_Sheet, Initial_Position)
		{
			Current_Grid = &Initial_Grid;
			Current_Grid->resumeAllCivClocks();
			Pocket_Watch.resume();
			is_bleeding = false;
			max_health = 100;
			weapon_damage = 100;
			time_between_attacks = 0.125;
			clip_size = 5;
			bullets_in_clip = clip_size;
			reload_duration = 4;
			stitching_duration = 4;
			Map_Dimensions = Map_Dimensions_;

			field_of_view = 160;
		}

public: PC(){}

private: sf::Vector2i Map_Dimensions;

/*Width of field of view, expressed in degrees*/
private: unsigned int field_of_view;

public: unsigned int getFOV(){return field_of_view;}

/*Return true if target point is visible to PC*/
public: bool fieldOfView(sf::Vector2f/*target*/
			);

/*Returns true if bullet hits target*/
public: bool attack(sf::Vector2f,//target
			float&//target's health
			);

public: Grid *Current_Grid;

public: void switchCurrentGrid();

public: void setHeadRotation();

/*Moves PC sprites, given no collision occurs*/
public: void movement(sf::Time /*time per frame*/
			);

public: bool is_bleeding;

private: float max_health;

public: float getMaxHealth(){return max_health;}

public: float getHealthPercentage(){return health / max_health;}

private: sf::Clock Reloading_Clock;

private: float reload_duration;

public: float getReloadingPercentage(){return Reloading_Clock.getElapsedTime().asSeconds() / reload_duration;}

public: bool isReloading();

private: float clip_size;

private: float bullets_in_clip;

public: int getClipSize(){return clip_size;}

public: int getBullets(){return bullets_in_clip;}

public: void decrementBulletsInClip(){if(bullets_in_clip > 0){bullets_in_clip--;}}

public: float getAmmoPercentage(){return bullets_in_clip / clip_size;}

public: bool reloading();

private: sf::Clock Attack_Clock;

public: void restartAttackClock(){Attack_Clock.restart();}

public: bool canAttack(){if(Attack_Clock.getElapsedTime().asSeconds() > time_between_attacks){return true;}return false;}

private: float time_between_attacks;

private: unsigned int weapon_damage;

private: sf::Clock Stitching_Clock;

public: float getStitchingPercentage(){return Stitching_Clock.getElapsedTime().asSeconds() / stitching_duration;}

private: unsigned int stitching_duration;

public: bool isStitching();

public: bool stitching();
};