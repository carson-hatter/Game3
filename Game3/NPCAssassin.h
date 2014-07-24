/*
* "NPCAssassin" is a child class of "HostileNPC"; this class defines scripts/
* states for the AI to follow.
* Instantiated in "Game."
*/
#pragma once

#include "HostileNPC.h"
#include "Dijkstras.h"

class NPCAssassin : public HostileNPC
{
public: NPCAssassin(sf::IntRect Body_Sprite_Texture, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position, Grid &Initial_Grid, BloodTrail &Blood_Trail_/*, std::string Difficulty*/) : HostileNPC(Body_Sprite_Texture, Character_Sprite_Sheet, Initial_Position, Initial_Grid, &Blood_Trail_/*, Difficulty*/)
		{
		}

private: sf::Clock Attack_Clock;

private: sf::Clock Search_Clock;

public: bool/*void*/ chooseScript(PC&
			);

private: bool/*void*/ attackScript(PC&
			 );

private: void huntScript(PC
			 );

private: void searchScript(sf::Vector2f
			 );
};