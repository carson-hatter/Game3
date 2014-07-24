/*
* "BloodTrail" is a utility class to manage any "BloodDrop" dropped if 
* PC::is_bleeding.
* Instantiated in "Game".
*/
#pragma once

#include "BloodDrop.h"
#include <cmath>

class BloodTrail
{	
private: std::vector<BloodDrop> Blood_Drops;

public: sf::CircleShape getBloodDropSprite(unsigned int i){return Blood_Drops[i].getSprite();}

public: unsigned int getBloodDropVectorSize(){return Blood_Drops.size();}

/*Searches Blood_Drops and removes any element which has expired.*/
public: void eraseExpiredBloodDrops();

/*If PC is over a given displacement from nearest BloodDrop instance, and
PC::is_bleeding, another BloodDrop instance will be pushed onto Blood_Drops.*/
public: void addBloodDrops(sf::Vector2f// PC Position
			);

public: BloodTrail();
};