/*
* "Character" is the parent class for playable and non-playable characters.
* The bulk of the class is handling the graphic representation of its child
* classes.
* Inheirited in "PC" and "NPC".
*/
#pragma once
#define PI 3.142857
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "PauseableSFClock.h"

class Character
{
/*Begins at 100; if less than or equal to zero, Character's stop moving*/
public: float health;

public: bool isDead(){if(health <= 0){return true;}return false;}

protected: unsigned int weapon_damage;

protected: PauseableSFClock Pocket_Watch;

public: void resumePocketWatch(){Pocket_Watch.resume();}

/************BEGIN MOVMENT MEMBERS***********************/

/*How far Character's sprites move per frame*/
protected: unsigned int speed;

/*"STANDING" means the tips of the Character's feet are visible in front of
their body; the other 2 enumerations put one foot foward and the other behind
the body sprite (to be referenced in movement())*/
protected: enum SpriteMovement {STANDING, WALKING1, WALKING2};

protected:  int max_movement_vector;

protected: SpriteMovement Sprite_Movement;

public: virtual void movement(sf::Time){return;}

/*Ref'd to determine what sprite should look like*/
protected: sf::Clock Movement_Clock;

/*************END MOVEMENT MEMBERS*****************/

/*******BEGIN SPRITE MEMBERS************************************************/

protected: sf::CircleShape Head_Sprite;

public: sf::CircleShape getHeadSprite(){return Head_Sprite;}

protected: sf::ConvexShape Body_Sprite;

protected: sf::ConvexShape Left_Foot_Sprite;

private: sf::Texture *Left_Foot_Sprite_Texture;

protected: sf::ConvexShape Right_Foot_Sprite;

private: sf::Texture *Right_Foot_Sprite_Texture;

protected: sf::ConvexShape Right_Arm_Sprite;

private: sf::Texture *Right_Arm_Sprite_Texture;

private: float body_half_width, body_half_height;

public: sf::ConvexShape getRightArmSprite(){return Right_Arm_Sprite;}

public: sf::ConvexShape getBodySprite(){return Body_Sprite;}

public: sf::ConvexShape getLeftFootSprite(){return Left_Foot_Sprite;}

public: sf::ConvexShape getRightFootSprite(){return Right_Foot_Sprite;}

public: void setBodySpritePosition(sf::Vector2f Pos){Body_Sprite.setPosition(Pos); updateCharacterSprite();}

/*Sets arm and foot sprites positions*/
public: void updateCharacterSprite();

/*Given a point on the map, simple geometry is run to rotate Character's sprites to face given point*/
public: void characterRotation(sf::Vector2f /*target position*/
			);


/********END OF SPRITE MEMBERS************************************************/

public: Character(sf::IntRect, /*texture rect for body sprite*/
			sf::Texture*, /*char sprite sheet*/
			sf::Vector2f /*initial position*/
			//Grid*//Pointer to current grid
			);

public: Character(){};
};