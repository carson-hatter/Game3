#pragma once

#include "Grid.h"

class IndustrialGrid : public Grid
{
public: IndustrialGrid(sf::Texture& Tall_Collisions_Sprite_Sheet,
			sf::Texture& Short_Collisions_Sprite_Sheet,
			sf::Texture& Floor_Tiles_Sprite_Sheet,
			sf::Texture& Street_And_Sidewalk_Sprite_Sheet,
			sf::FloatRect Boundary,
			sf::Texture& Character_Sprite_Sheet,
			unsigned int map_width_in_pix
			) : Grid(Tall_Collisions_Sprite_Sheet, Short_Collisions_Sprite_Sheet, Floor_Tiles_Sprite_Sheet, Street_And_Sidewalk_Sprite_Sheet, Boundary)
		{
			unsigned int number_of_designs = 1;
			
			unsigned int random_number = rand() % number_of_designs;

			if(random_number == 0)
			{
				Tall_Collisions.resize(4);
				Tall_Collisions[0].setPosition(350,350);
				Tall_Collisions[0].setSize(sf::Vector2f(50,50));
				Tall_Collisions[1].setPosition(1600,1600);
				Tall_Collisions[1].setSize(sf::Vector2f(50,50));
				Tall_Collisions[2].setPosition(350,1600);
				Tall_Collisions[2].setSize(sf::Vector2f(50,50));
				Tall_Collisions[3].setPosition(1600,350);
				Tall_Collisions[3].setSize(sf::Vector2f(50,50));
				//Tall_Collisions[4].setPosition(2650,4700);
				//Tall_Collisions[4].setSize(sf::Vector2f(1100,50));
				//Tall_Collisions[5].setPosition(750,4700);
				//Tall_Collisions[5].setSize(sf::Vector2f(1700,50));
				//Tall_Collisions[6].setPosition(750,1650);
				//Tall_Collisions[6].setSize(sf::Vector2f(50,3050));
				//Tall_Collisions[7].setPosition(750,800);
				//Tall_Collisions[7].setSize(sf::Vector2f(50,650));

				Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(1850,1750,300,300));

				Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1850,1750,300,300)));

				//Family_Member_Hash_Vectors.push_back(HashVector(sf::FloatRect(Boundary.left + 1025, Boundary.top + 1325, 25, 100), 0, 90, 10));

				std::vector<HashVector> Temp;
				Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1050, Boundary.top + 1050, 300, 300), 0, 90, 10));
				Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1450, Boundary.top + 1050, 300, 300), 0, 90, 10));

				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(1050,1050), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(1050,1050), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

			}


			//Testing only:
			for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
			{
				Tall_Collisions[i].setFillColor(sf::Color::Yellow);
			}

			moveEverything();
		}
};