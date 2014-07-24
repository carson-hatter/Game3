/*
* "NPC" is a child of "Character" and a parent to both "PassiveNPC" and
* "HostileNPC". This class hosts the aggravation timer and the path generated
* by pathfinding functions. (Passive and hostile npc's need different
* pathfinding functions because passive npc's are tethered to one grid while
* hostile npc's can travel between grids).
*/
#pragma once
#define DIJKSTRASSIZE 50
#include "Character.h"
#include "Dijkstras.h"


class NPC : public Character, public Dijkstras
{
public: NPC(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position/*,*/ /*std::vector<std::vector<Dijkstras::neighbor> > *Adjacency_List_,*/ /*sf::FloatRect Adj_List_Boundary_*/) : Character(Body_Sprite_Texture_Rect, Character_Sprite_Sheet, Initial_Position), Dijkstras()
		{};

public: NPC()
		{};

protected: virtual void pathFinding(unsigned int
			   )
		   {};

protected: std::list<sf::Vector2f> Path_To_Destination;

public: bool isPathToDestinationEmpty(){if(Path_To_Destination.empty()){return true;}return false;} 

public: virtual unsigned int convertSFMLToDijkstras(sf::Vector2f /*target to convert*/
			){return 0;};

public: virtual sf::Vector2f convertDijkstrasToSFML(unsigned int /*target to convert*/
			){return sf::Vector2f(0,0);};

public: void movement(sf::Time /*time per frame*/
			);

protected: PauseableSFClock Aggro_Clock;

protected: unsigned int aggro_time_limit;

public: bool isAggro();

public: void pauseAggroClock(){Aggro_Clock.pause();}

public: void resumeAggroClock(){Aggro_Clock.resume();}
};