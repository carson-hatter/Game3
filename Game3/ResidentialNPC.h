#pragma once

#include "ResidentialGrid.h"
#include "NPC.h"

class ResidentialNPC : public NPC
{
public: ResidentialNPC(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position, std::vector<std::vector<Dijkstras::neighbor> > *Adjacency_List_, unsigned int map_width_in_pix_, ResidentialGrid *Initial_Grid) : NPC(Body_Sprite_Texture_Rect, Character_Sprite_Sheet, Initial_Position, /*std::vector<std::vector<Dijkstras::neighbor> >*/ Adjacency_List_, /*unsigned int*/ map_width_in_pix_)
		{
			Current_Grid = Initial_Grid;
		}
protected: ResidentialGrid *Current_Grid;
};