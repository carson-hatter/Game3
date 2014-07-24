/*
* "Game" is the master class which directs all 
* PC/NPC/BloodTrail/BloodSplatter/Grid/HUD interaction. Like "PreGameMenu" and
* "GameOverScreen", this is one of the few user interfaces of this program.
* Instantiated in main.cpp.
*/
#pragma once

#include "BloodSplatter.h"
#include "BloodTrail.h"
#include "PC.h"
#include "NPCAssassin.h"
#include "Grid.h"
#include "HUD.h"
#include <fstream>
#include <sstream>


class Game
{
/*Referenced when updating high scores, is 'isGameOver()'*/
private: unsigned int hostiles_killed;

/*Referenced when updating high scores, is 'isGameOver()'*/
private: sf::Clock Seconds_Alive_Clock;

public: Game(sf::RenderWindow&
			);

/*References PC::health; if dead, "hiscores.txt" is updated, and in main.cpp
"GameOverScreen" is instantiated, and "Game" instance is deleted.*/
public: bool isGameOver();

private: unsigned int map_width;

private: std::vector<std::vector<Grid> > Map;

private: sf::Vector2i convertSFMLToMapIndex(sf::Vector2f
			 );

/**************BEGIN PC MEMBERS**************************************/

private: PC P_C;

private: sf::View P_C_Centered_View;

public: void regenPCHealth(sf::Time
			);

public: void pcRotation(sf::Vector2f
			);

private: void pcAttack();

private: HUD H_U_D;

public: void updateHUD();

/*********************END PC MEMBERS*************************/


/***********BEGIN TEXTURES***************************************/

private: sf::Texture Character_Sprite_Sheet;

private: sf::Texture Tall_Collisions_Sprite_Sheet;

private: sf::Texture Short_Collisions_Sprite_Sheet;

private: sf::Texture Floor_Tiles_Sprite_Sheet;

private: sf::Texture Street_Sprite_Sheet;

/*******************END TEXTURES******************************/

/******************BEGIN SOUNDS***************************************/

private: sf::SoundBuffer Gun_Shot_Buffer;

private: sf::Sound Gun_Shot;

private: sf::SoundBuffer Dry_Fire_Buffer;

private: sf::Sound Dry_Fire;

private: sf::SoundBuffer Reloading_Buffer;

private: sf::Sound Reloading;

private: sf::SoundBuffer Stitching_Buffer;

private: sf::Sound Stitching;

/*******************END SOUNDS******************************************/

/***********BEGIN BLOOD MEMBERS************************************/

private: BloodTrail Blood_Trail;

private: std::vector<BloodSplatter> Blood_Splatters;

public: void processBloodTrail();

public: void eraseExpiredBloodSplatters();

/*******************END BLOOD MEMBERS*******************************/

/********************BEGIN NPC MEMBERS******************************/

private: std::vector<HostileNPC*> Hostile_NPCs;

/*The HostileNPC at this iterator in Hostile_NPCs will have their scripting
processed*/
private: unsigned int hostile_npcs_vector_iterator;

public: void incrementNPCIterators();

public: void buildDeathSprites();

public: void npcScripting();

private: unsigned int countLivingHostileNPCs();

public: void spawnHostileNPCs();

private: unsigned int minimum_number_of_hostile_npcs;

/*********************END NPC MEMBERS***************************************/

/*Handles movement for PC, passive npcs, and Hostile_NPCs; also, their 
updateCharacterSprite functions are called*/
public: void moveCharacterSprites(sf::Time// time per frame
			);

public: void drawEverything(sf::RenderWindow&
			);

/*Called when PC or a hostile npc fires a gun. All passive npcs in current
grid, as well as any hostile npc in the eight surrounding grids, are aggravated*/
private: void gunShot(Grid*
			 );

public: void eventHandling(sf::RenderWindow&
			);

private: void determinePassiveNPCsRotations();

public: void playGridSFX();
};