/*
* "HostileNPC" is a child class of "NPC" and a parent to "NPCAssassin". This
* class gives hostile npcs the ability of sight and pathfinding.
* Instantiated in "Game".
*/
#pragma once

#include "BloodTrail.h"
#include "NPC.h"
#include "Dijkstras.h"
#include "Grid.h"
#include "PC.h"

class HostileNPC : public NPC
{
public: HostileNPC(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position, Grid &Initial_Grid, BloodTrail *Blood_Trail_/*, std::string Difficulty*/) : NPC(Body_Sprite_Texture_Rect, Character_Sprite_Sheet, Initial_Position)
		{
			death_sprite_constructed = false;
			jogging_speed = (speed * 2);
			walking_speed = speed;
			Current_Grid = &Initial_Grid;
			Blood_Trail = Blood_Trail_;
			weapon_damage = 30;
			aggro_time_limit = 10;
		}

public: HostileNPC(){};

public: void restartAggroClock(){Aggro_Clock.restart(); Path_To_Destination.clear();}

protected: BloodTrail *Blood_Trail;

protected: bool isBloodDropVisible(sf::Vector2f
			 );

protected: Grid *Current_Grid;

public: Grid* getCurrentGrid(){return Current_Grid;}

public: void switchCurrentGrid();

public: virtual bool/*void*/ chooseScript(PC& 
		){return false;}

protected: void pathFinding(unsigned int
			   );

public: unsigned int convertSFMLToDijkstras(sf::Vector2f /*target to convert*/
			);

public: sf::Vector2f convertDijkstrasToSFML(unsigned int /*target to convert*/
			);

/*Returns true if target point is visible to PC*/
protected: bool fieldOfView(sf::Vector2f/*target*/
			);

protected: unsigned int jogging_speed;

protected: unsigned int walking_speed;

/************BEGIN DEATH SPRITE MEMBERS****************************/

private: std::vector<sf::ConvexShape> Death_Sprite;

private: sf::CircleShape Death_Sprite_Head;

public: sf::CircleShape getDeathSpriteHead(){return Death_Sprite_Head;}

public: unsigned int getDeathSpriteVectorSize(){return Death_Sprite.size();}

public: sf::ConvexShape getDeathSpritePiece(unsigned int i){return Death_Sprite[i];}

public: void constructDeathSprite();

public: bool death_sprite_constructed;

/*****************END DEATH SPRITE MEMBERS*********************/
};