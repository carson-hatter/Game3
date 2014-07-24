#pragma once
#include "HashVector.h"
#include "NPC.h"


class PassiveNPC : public NPC
{
public: PassiveNPC(){};

public: PassiveNPC(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position, /*std::vector<std::vector<Dijkstras::neighbor> > *Adjacency_List_,*/ sf::FloatRect Adj_List_Boundary_, std::vector<HashVector> Hash_Vectors_, std::vector<HashVector> Flee_Boxes_) : NPC(Body_Sprite_Texture_Rect, Character_Sprite_Sheet, Initial_Position/*,*/ /*Adjacency_List_,*/ /*Adj_List_Boundary_*/)
		{
			Current_Hash_Vector = NULL;
			standing_still_time_limit = 10;
			aggro_time_limit = 5;

			Hash_Vectors = Hash_Vectors_;
			Flee_Boxes = Flee_Boxes_;

			Adj_List_Boundary = Adj_List_Boundary_;
		};

public: void chooseScript(
			);

private: unsigned int standing_still_time_limit;

public: void restartPocketWatch(){Pocket_Watch.restart();}

private: PauseableSFClock Default_Clock;

public: void resumeDefaultClock(){Default_Clock.resume();}

public: void pauseDefaultClock(){Default_Clock.pause();}

public: void restartAggroClock(){if(!isAggro()){Path_To_Destination.clear();} Aggro_Clock.restart();}

private: sf::FloatRect Adj_List_Boundary;

private: std::vector<HashVector> Hash_Vectors;

private: std::vector<HashVector> Flee_Boxes;

public: HashVector *Current_Hash_Vector;

public: void setAdjList(std::vector<std::vector<Dijkstras::neighbor> > *A_L){Adjacency_List = A_L;}

private: std::vector<std::vector<Dijkstras::neighbor> > *Adjacency_List;

public: void moveNPC(float x, float y){Body_Sprite.move(x,y);}

private: void defaultScript();

private: void fleeScript();

public: void determineRotation();

protected: void pathFinding(unsigned int
			   );

public: unsigned int convertSFMLToDijkstras(sf::Vector2f /*target to convert*/
			);

public: sf::Vector2f convertDijkstrasToSFML(unsigned int /*target to convert*/
			);
};