#pragma once

#include "ResidentialNPC.h"

class NPCFamilyMember : public ResidentialNPC
{
public: NPCFamilyMember(sf::IntRect Body_Sprite_Texture, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position, std::vector<std::vector<Dijkstras::neighbor> > *Adjacency_List_, unsigned int map_width_in_pix_, ResidentialGrid *Initial_Grid) : ResidentialNPC(Body_Sprite_Texture, Character_Sprite_Sheet, Initial_Position, Adjacency_List_, map_width_in_pix_, Initial_Grid)
		{};
public: void chooseScript(Character*
			);
private: sf::Clock Wander_Clock;
private: unsigned int standing_still_time_limit;
private: void wanderScript();
private: void fleeScript(Character*
			 );
private: Grid::HashVector *Current_Hash_Vector;
};