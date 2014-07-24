#pragma once

#include "Grid.h"

class CommercialGrid : public Grid
{
public: CommercialGrid(sf::Texture& Tall_Collisions_Sprite_Sheet,
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
				Tall_Collisions.push_back(buildWall(sf::Vector2f(350,350), sf::Vector2f(1450,400), Tall_Collisions_Sprite_Sheet));
				Tall_Collisions.push_back(buildWall(sf::Vector2f(1600,350), sf::Vector2f(1650,1650), Tall_Collisions_Sprite_Sheet));
				
				//Short_Collisions.push_back(buildDiningTable(sf::Vector2f(450,400), sf::Vector2f(550,600), Short_Collisions_Sprite_Sheet));
				//Short_Collisions.push_back(buildExpoTable(sf::Vector2f(700,1350), sf::Vector2f(1000,1400), Short_Collisions_Sprite_Sheet));
				//Short_Collisions.push_back(buildGrill(sf::Vector2f(800,1550), sf::Vector2f(900,1600), Short_Collisions_Sprite_Sheet));
				//Short_Collisions.push_back(buildSink(sf::Vector2f(1300,1550), sf::Vector2f(1350,1600), Short_Collisions_Sprite_Sheet, 180));

				Floor_Tiles.push_back(buildTestFloorTile(sf::Vector2f(400,1650), sf::Vector2f(450,1700)));

				Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(1300,650,50,50));

				Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1300,650,50,50)));
				Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1500,1300,50,50)));

				std::vector<HashVector> Temp;
				Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 650, Boundary.top + 750, 50, 100), 0, 4, 10));
				Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1050, Boundary.top + 950, 50, 100), 178, 182, 10));

				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
				Passive_NPCs.push_back(PassiveNPC(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, sf::Vector2f(0,0), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

			}

			//Testing only:
			//for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
			//{
			//	Tall_Collisions[i].setFillColor(sf::Color::Blue);
			//}
			moveEverything();
		}
private: sf::RectangleShape buildWall(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
private: sf::RectangleShape buildDiningTable(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
 private: sf::RectangleShape buildExpoTable(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
private: sf::RectangleShape buildGrill(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
private: sf::RectangleShape buildChair(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&,
			 float
			 );
private: sf::RectangleShape buildToilet(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&,
			 float
			 );
private: sf::RectangleShape buildSink(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&,
			 float
			 );
private: sf::RectangleShape buildTestFloorTile(sf::Vector2f,
		  sf::Vector2f
		  );
};