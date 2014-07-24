/*
* "Grid" represents each city block of the game, holding members which define
* /manipulate the buildings, the civilian npc's who roam them, where hostile 
* npc's will spawn or wander to, and background sound effects.
* Instantiated in "Game".
*/

#pragma once
#include "HashVector.h"
#include "BackgroundSFX.h"
#include <SFML/Graphics.hpp>
#include "PassiveNPC.h"
#include <iostream>
#include <cmath>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/segment.hpp> 
#include <boost/geometry/algorithms/intersection.hpp>
#include <boost/geometry/geometries/point_xy.hpp>



class Grid
{
public: Grid(sf::Texture&, //tall collisions
			sf::Texture&, //short collisions
			sf::Texture&, //floor tiles
			sf::Texture&,//street sheet
			sf::FloatRect //boundary
			);

protected: void moveEverything();

public: Grid();

private: bool lineLineIntersection(sf::Vector2f,
			 sf::Vector2f,
			 sf::Vector2f,
			 sf::Vector2f
			 );

public: bool lineOfSight(sf::Vector2f,//origin point
			sf::Vector2f//end point
			);

private: float max(float, float);

private: float min(float, float);

protected: sf::FloatRect Boundary;

public: sf::FloatRect getBoundary(){return Boundary;}

/*Where hostile npc's can spawn*/
protected: HashVector Hostile_NPC_Spawn_Vector;

/*Where hostile npc's can wander*/
public: std::vector<HashVector> Assassin_Hash_Vectors;

public: HashVector getHostileNPCSpawnVector(){return Hostile_NPC_Spawn_Vector;}

public: void drawEverything(sf::RenderWindow&
			);

/***************BEGIN MAP OBJECT MEMBERS**************************************/

/*Rectangle shapes that characters cant walk over, but can see over*/
protected: std::vector<sf::RectangleShape> Short_Collisions;

public: bool shortCollisionsDetection(sf::Vector2f
			 );

public: unsigned int getShortCollisionsVectorSize(){return Short_Collisions.size();}

public: sf::RectangleShape getShortCollision(unsigned int i){return Short_Collisions[i];}

/*Rectangle shapes that characters cant walk over and cant see over*/
protected: std::vector<sf::RectangleShape> Tall_Collisions;

public: bool tallCollisionsDetection(sf::Vector2f
			);

public: unsigned int getTallCollisionsVectorSize(){return Tall_Collisions.size();}

public: sf::RectangleShape getTallCollision(unsigned int i){return Tall_Collisions[i];}

/*Rectangle shapes that can be walked over and seen over*/
protected: std::vector<sf::RectangleShape> Floor_Tiles;

public: unsigned int getFloorTilesVectorSize(){return Floor_Tiles.size();}

public: sf::RectangleShape getFloorTile(unsigned int i){return Floor_Tiles[i];}

/************************END MAP OBJECT MEMBERS*******************************/

/************BEGIN NEIGHBORING GRIDS*******************************/

public: Grid *North_Grid;

public: Grid *Northeast_Grid;

public: Grid *East_Grid;

public: Grid *Southeast_Grid;

public: Grid *South_Grid;

public: Grid *Southwest_Grid;

public: Grid *West_Grid;

public: Grid *Northwest_Grid;

/****************END NEIGHBORING GRIDS**********************/

/*****************BEGIN PASSIVE NPC MEMBERS***************************/

/*Where passive npc's can flee*/
protected: std::vector<HashVector> Flee_Boxes;

public: void updateCharacterSprites();

public: void moveCharacterSprites(sf::Time
			);

protected: bool isNPCContainedInFleeBoxes(sf::Vector2f//npc position
			   );
public: void incrementPassiveNPCIterators();

public: void passiveNPCsScripting();

public: void setPassiveNPCsAdjLists();

/*The element at this index of Passive_NPCs will process their scripting*/
private: unsigned int passive_npcs_iterator;

public: void restartAggroClocks();

public: void determinePassiveNPCsRotations();

protected: std::vector<PassiveNPC> Passive_NPCs;

public: unsigned int getPassiveNPCsVectorSize(){return Passive_NPCs.size();}

public: PassiveNPC getPassiveNPC(unsigned int i){return Passive_NPCs[i];}

public: void pauseAllCivClocks();

public: void resumeAllCivClocks();

public: void restartAllCivPocketWatches();

private: sf::IntRect generateCivilianBodySpriteTextRect();

/******************END PASSIVE NPCS MEMBERS********************************/

/*************BEGIN SFX MEMBERS******************************************/

private: std::vector<BackgroundSFX> Background_SFX;

public: void playBackgroundSFX(sf::Vector2f
			);

public: void stopBackgroundSFX();

/*******************END SFX MEMBERS*************************************/

/****************BEGIN ADJ. LIST MEMBERS***********************************/

private: std::vector<std::vector<Dijkstras::neighbor> > Adjacency_List;

public: std::vector<std::vector<Dijkstras::neighbor> >* getAdjList(){return &Adjacency_List;}

public: void buildAdjList();

private: bool adjListCollisionDetection(sf::Vector2f
			 );

private: sf::FloatRect Adj_List_Boundary;

public: sf::FloatRect getAdjListBoundary(){return Adj_List_Boundary;}

/*******************END ADJ. LIST MEMBERS*******************************/

/*********BEGIN BUILD MAP OBJECTS MEMBERS***********************/

private: sf::RectangleShape buildDinerFloor(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
private: sf::RectangleShape buildAlleyFloor(sf::Vector2f,
			 sf::Vector2f,
			 sf::Texture&
			 );
private: sf::RectangleShape buildWallOne(sf::Vector2f,
		  sf::Vector2f,
		  sf::Texture&
		  );
private: sf::RectangleShape buildFryers(sf::Vector2f,
		sf::Texture&,
		float
		);
private:sf::RectangleShape buildGrill(sf::Vector2f,
		sf::Texture&,
		float
		);
private:sf::RectangleShape buildExpoTable(sf::Vector2f,
		sf::Texture&,
		float
		);
private: sf::RectangleShape buildBathroomSink(sf::Vector2f,
		sf::Texture&,
		float
		);
private: sf::RectangleShape buildDiningTable(sf::Vector2f,
		sf::Vector2f,
		sf::Texture&
		);
private: sf::RectangleShape buildToilet(sf::Vector2f,
			  sf::Texture&,
			  float
			  );
private: sf::RectangleShape buildDiningChair(sf::Vector2f,
		   sf::Texture&,
		   float
		   );
private: sf::RectangleShape buildDiningBooth(sf::Vector2f,
			sf::Texture&,
			float
			);
private: sf::RectangleShape buildCashRegister(sf::Vector2f,
		  sf::Texture&,
		  float
		  );
private: sf::RectangleShape buildCounter(sf::Vector2f,
		   sf::Vector2f,
		   sf::Texture&
		   );
private: sf::RectangleShape buildGroceryShelves(sf::Vector2f,
			 sf::Texture&,
			 float
			 );
private: sf::RectangleShape buildCar(sf::Vector2f,
		  sf::Texture&,
		  float
		  );
private: sf::RectangleShape buildToolTable(sf::Vector2f,
		   sf::Texture&,
		   float
		   );
private: sf::RectangleShape buildBoxes(sf::Vector2f,
		  sf::Vector2f,
		  sf::Texture&
		  );
private: sf::RectangleShape buildLiquorShelf(sf::Vector2f,
		  sf::Texture&,
		  float
		  );
private: sf::RectangleShape buildFloorZero(sf::Vector2f,
		  sf::Vector2f,
		  sf::Texture&
		  );
private: sf::RectangleShape buildFloorOne(sf::Vector2f,
		  sf::Vector2f,
		  sf::Texture&
		  );
/****************END BUILD MAP OBJECTS MEMBERS********************/
};