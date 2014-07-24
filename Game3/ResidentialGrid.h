#pragma once

#include "Grid.h"

class ResidentialGrid : public Grid
{
public: ResidentialGrid(sf::Texture& Tall_Collisions_Sprite_Sheet,
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

			std::vector< HashVector > Family_Member_Hash_Vectors;

			if(random_number == 0)
			{
				Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1150,1450,200,200)));

				Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(1150,1450,200,200));

				Tall_Collisions.resize(4);

				Tall_Collisions[0].setPosition(350,350);
				Tall_Collisions[0].setSize(sf::Vector2f(50,50));
				Tall_Collisions[1].setPosition(1600,1600);
				Tall_Collisions[1].setSize(sf::Vector2f(50,50));
				Tall_Collisions[2].setPosition(350,1600);
				Tall_Collisions[2].setSize(sf::Vector2f(50,50));
				Tall_Collisions[3].setPosition(1600,350);
				Tall_Collisions[3].setSize(sf::Vector2f(50,50));
				//Tall_Collisions[0].setPosition(500,700);
				//Tall_Collisions[0].setSize(sf::Vector2f(250,50));
				//Tall_Collisions[1].setPosition(750,700);
				//Tall_Collisions[1].setSize(sf::Vector2f(200,50));
				//Tall_Collisions[2].setPosition(1050,700);
				//Tall_Collisions[2].setSize(sf::Vector2f(200,50));
				//Tall_Collisions[3].setPosition(1250,850);
				//Tall_Collisions[3].setSize(sf::Vector2f(400,50));
				//Tall_Collisions[4].setPosition(1250,700);
				//Tall_Collisions[4].setSize(sf::Vector2f(50,150));
				//Tall_Collisions[5].setPosition(500,750);
				//Tall_Collisions[5].setSize(sf::Vector2f(50,300));
				//Tall_Collisions[6].setPosition(750,750);
				//Tall_Collisions[6].setSize(sf::Vector2f(50,300));
				//Tall_Collisions[7].setPosition(1250,1000);
				//Tall_Collisions[7].setSize(sf::Vector2f(50,300));
				//Tall_Collisions[8].setPosition(1600,900);
				//Tall_Collisions[8].setSize(sf::Vector2f(50,400));
				//Tall_Collisions[9].setPosition(500,1150);
				//Tall_Collisions[9].setSize(sf::Vector2f(100,50));
				//Tall_Collisions[10].setPosition(900,1150);
				//Tall_Collisions[10].setSize(sf::Vector2f(250,50));
				//Tall_Collisions[11].setPosition(600,1150);
				//Tall_Collisions[11].setSize(sf::Vector2f(50,300));
				//Tall_Collisions[12].setPosition(900,1200);
				//Tall_Collisions[12].setSize(sf::Vector2f(50,250));
				//Tall_Collisions[13].setPosition(600,1450);
				//Tall_Collisions[13].setSize(sf::Vector2f(500,50));
				//Tall_Collisions[14].setPosition(800,1500);
				//Tall_Collisions[14].setSize(sf::Vector2f(50,150));
				//Tall_Collisions[15].setPosition(850,1600);
				//Tall_Collisions[15].setSize(sf::Vector2f(800,50));
				//Tall_Collisions[16].setPosition(1100,1300);
				//Tall_Collisions[16].setSize(sf::Vector2f(50,200));
				//Tall_Collisions[17].setPosition(1250,1300);
				//Tall_Collisions[17].setSize(sf::Vector2f(400,50));
				//Tall_Collisions[18].setPosition(1600,1350);
				//Tall_Collisions[18].setSize(sf::Vector2f(50,250));

				Family_Member_Hash_Vectors.push_back(HashVector(sf::FloatRect(Boundary.left + 600, Boundary.top + 950, 50, 50), 0, 90, 10));
				Family_Member_Hash_Vectors.push_back(HashVector(sf::FloatRect(Boundary.left + 850, Boundary.top + 900, 50, 50), 180, 90, 10));
				Family_Member_Hash_Vectors.push_back(HashVector(sf::FloatRect(Boundary.left + 1050, Boundary.top + 1300, 50, 50), 0, 90, 10));
				
		/*		std::vector<std::vector<Dijkstras::neighbor> > *Null_Adj_List;
				Null_Adj_List = NULL;*/

				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Family_Member_Hash_Vectors, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Family_Member_Hash_Vectors, Flee_Boxes));

			}

			//Testing only:
			for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
			{
				Tall_Collisions[i].setFillColor(sf::Color::Green);
			}

			moveEverything();
		}
};