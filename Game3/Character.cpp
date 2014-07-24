#include "Character.h"

Character::Character(sf::IntRect Body_Sprite_Texture_Rect, sf::Texture *Character_Sprite_Sheet, sf::Vector2f Initial_Position)
{
	//Current_Grid = Initial_Grid;

	Head_Sprite.setRadius(12.5);
	Head_Sprite.setOrigin(12.5,12.5);
	Head_Sprite.setTexture(Character_Sprite_Sheet);

	Body_Sprite.setPointCount(8);
	Body_Sprite.setPoint(0, sf::Vector2f(0,5));
	Body_Sprite.setPoint(1, sf::Vector2f(5,0));
	Body_Sprite.setPoint(2, sf::Vector2f(20,0));
	Body_Sprite.setPoint(3, sf::Vector2f(25,5));
	Body_Sprite.setPoint(4, sf::Vector2f(25,95));
	Body_Sprite.setPoint(5, sf::Vector2f(20,100));
	Body_Sprite.setPoint(6, sf::Vector2f(5,100));
	Body_Sprite.setPoint(7, sf::Vector2f(0,95));
	body_half_width = 12.5;
	body_half_height = 50;
	Body_Sprite.setOrigin(body_half_width, body_half_height);
	body_half_width *= .9;
	body_half_height *= .9;
	Body_Sprite.setTexture(Character_Sprite_Sheet);
	Body_Sprite.setTextureRect(Body_Sprite_Texture_Rect);

	Left_Foot_Sprite.setPointCount(8);
	Left_Foot_Sprite.setPoint(0, sf::Vector2f(5,0));
	Left_Foot_Sprite.setPoint(1, sf::Vector2f(20,0));
	Left_Foot_Sprite.setPoint(2, sf::Vector2f(25,5));
	Left_Foot_Sprite.setPoint(3, sf::Vector2f(25,15));
	Left_Foot_Sprite.setPoint(4, sf::Vector2f(20,20));
	Left_Foot_Sprite.setPoint(5, sf::Vector2f(5,20));
	Left_Foot_Sprite.setPoint(6, sf::Vector2f(0,15));
	Left_Foot_Sprite.setPoint(7, sf::Vector2f(0,5));
	Left_Foot_Sprite.setOrigin(12.5, 10);
	Left_Foot_Sprite.setTexture(Character_Sprite_Sheet);

	Right_Foot_Sprite.setPointCount(8);
	Right_Foot_Sprite.setPoint(0, sf::Vector2f(5,0));
	Right_Foot_Sprite.setPoint(1, sf::Vector2f(20,0));
	Right_Foot_Sprite.setPoint(2, sf::Vector2f(25,5));
	Right_Foot_Sprite.setPoint(3, sf::Vector2f(25,15));
	Right_Foot_Sprite.setPoint(4, sf::Vector2f(20,20));
	Right_Foot_Sprite.setPoint(5, sf::Vector2f(5,20));
	Right_Foot_Sprite.setPoint(6, sf::Vector2f(0,15));
	Right_Foot_Sprite.setPoint(7, sf::Vector2f(0,5));
	Right_Foot_Sprite.setOrigin(12.5, 10);
	Right_Foot_Sprite.setTexture(Character_Sprite_Sheet);

	Right_Arm_Sprite.setPointCount(8);
	Right_Arm_Sprite.setPoint(0, sf::Vector2f(5, 0));
	Right_Arm_Sprite.setPoint(1, sf::Vector2f(65, 0));
	Right_Arm_Sprite.setPoint(2, sf::Vector2f(70, 3));
	Right_Arm_Sprite.setPoint(3, sf::Vector2f(70, 9));
	Right_Arm_Sprite.setPoint(4, sf::Vector2f(65, 12));
	Right_Arm_Sprite.setPoint(5, sf::Vector2f(5, 12));
	Right_Arm_Sprite.setPoint(6, sf::Vector2f(0, 9));
	Right_Arm_Sprite.setPoint(7, sf::Vector2f(0, 3));
	Right_Arm_Sprite.setOrigin(5, 5);
	Right_Arm_Sprite.setTexture(Character_Sprite_Sheet);

	speed = 300;
	health = 100;
	Body_Sprite.setPosition(Initial_Position);

	if((Body_Sprite_Texture_Rect.left == 0) && (Body_Sprite_Texture_Rect.top == 0))
	{
		Left_Foot_Sprite.setTextureRect(sf::IntRect(150,0,25,20));
		Right_Foot_Sprite.setTextureRect(sf::IntRect(150,0,25,20));
		Right_Arm_Sprite.setTextureRect(sf::IntRect(50,0,51,11));
		Head_Sprite.setTextureRect(sf::IntRect(200,0,25,25));
	}
	else if((Body_Sprite_Texture_Rect.left == 250) && (Body_Sprite_Texture_Rect.top == 0))
	{
		Left_Foot_Sprite.setTextureRect(sf::IntRect(325,0,25,20));
		Right_Foot_Sprite.setTextureRect(sf::IntRect(325,0,25,20));
		Right_Arm_Sprite.setTextureRect(sf::IntRect(275,0,50,10));
		Head_Sprite.setTextureRect(sf::IntRect(350,0,25,25));
	}
	else
	{
		Left_Foot_Sprite.setTextureRect(sf::IntRect(Body_Sprite_Texture_Rect.left, Body_Sprite_Texture_Rect.top + Body_Sprite_Texture_Rect.height, 25, 20));
		Right_Foot_Sprite.setTextureRect(sf::IntRect(Body_Sprite_Texture_Rect.left, Body_Sprite_Texture_Rect.top + Body_Sprite_Texture_Rect.height, 25, 20));
		Head_Sprite.setTextureRect(sf::IntRect(Left_Foot_Sprite.getTextureRect().left, Left_Foot_Sprite.getTextureRect().top + Left_Foot_Sprite.getTextureRect().height, 25, 25));

	}

	Sprite_Movement = STANDING;

	max_movement_vector = 3;
}

void Character::characterRotation(sf::Vector2f Target_Position)
{
	float result, x_diff, y_diff;
	
	x_diff = Target_Position.x - Body_Sprite.getPosition().x;
	
	y_diff = Target_Position.y - Body_Sprite.getPosition().y;
	
	result = atan2(y_diff, x_diff);
	
	result = ((result*180) / 3.14159265);
	
	Body_Sprite.setRotation(result);

	x_diff = Target_Position.x - Right_Arm_Sprite.getPosition().x;
	
	y_diff = Target_Position.y - Right_Arm_Sprite.getPosition().y;
	
	result = atan2(y_diff, x_diff);
	
	result = ((result*180) / 3.14159265);

	Right_Arm_Sprite.setRotation(result);
}

void Character::updateCharacterSprite()
{
	Head_Sprite.setPosition(Body_Sprite.getPosition());

	Left_Foot_Sprite.setRotation(Body_Sprite.getRotation());
	Right_Foot_Sprite.setRotation(Body_Sprite.getRotation());
	Right_Arm_Sprite.setRotation(Body_Sprite.getRotation());

	sf::Vector2f New_Position;
	New_Position.x = Body_Sprite.getPosition().x + (body_half_width*cos((Body_Sprite.getRotation()/180)*PI)) - (body_half_height*sin((Body_Sprite.getRotation()/180)*PI));
	New_Position.y = Body_Sprite.getPosition().y + (body_half_width*sin((Body_Sprite.getRotation()/180)*PI)) + (body_half_height*cos((Body_Sprite.getRotation()/180)*PI));
	Right_Arm_Sprite.setPosition(New_Position);

	if(Sprite_Movement == STANDING)
	{
		sf::Vector2f Left_Foot_Position;
		Left_Foot_Position.x = Body_Sprite.getPosition().x + (5*cos((Body_Sprite.getRotation()/180)*PI)) - (35*sin((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Position.y = Body_Sprite.getPosition().y + (5*sin((Body_Sprite.getRotation()/180)*PI)) + (35*cos((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Sprite.setPosition(Left_Foot_Position);				

		sf::Vector2f Right_Foot_Position;
		Right_Foot_Position.x = Body_Sprite.getPosition().x - (-5*cos((Body_Sprite.getRotation()/180)*PI)) + (35*sin((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Position.y = Body_Sprite.getPosition().y - (-5*sin((Body_Sprite.getRotation()/180)*PI)) - (35*cos((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Sprite.setPosition(Right_Foot_Position);
	}
	
	if(Sprite_Movement == WALKING1)
	{
		sf::Vector2f Left_Foot_Position;
		Left_Foot_Position.x = Body_Sprite.getPosition().x + (16*cos((Body_Sprite.getRotation()/180)*PI)) - (35*sin((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Position.y = Body_Sprite.getPosition().y + (16*sin((Body_Sprite.getRotation()/180)*PI)) + (35*cos((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Sprite.setPosition(Left_Foot_Position);				

		sf::Vector2f Right_Foot_Position;
		Right_Foot_Position.x = Body_Sprite.getPosition().x - (10*cos((Body_Sprite.getRotation()/180)*PI)) + (35*sin((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Position.y = Body_Sprite.getPosition().y - (10*sin((Body_Sprite.getRotation()/180)*PI)) - (35*cos((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Sprite.setPosition(Right_Foot_Position);
	}

	if(Sprite_Movement == WALKING2)
	{
		sf::Vector2f Right_Foot_Position;
		Right_Foot_Position.x = Body_Sprite.getPosition().x - (-16*cos((Body_Sprite.getRotation()/180)*PI)) + (35*sin((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Position.y = Body_Sprite.getPosition().y - (-16*sin((Body_Sprite.getRotation()/180)*PI)) - (35*cos((Body_Sprite.getRotation()/180)*PI));
		Right_Foot_Sprite.setPosition(Right_Foot_Position);				

		sf::Vector2f Left_Foot_Position;
		Left_Foot_Position.x = Body_Sprite.getPosition().x + (-10*cos((Body_Sprite.getRotation()/180)*PI)) - (35*sin((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Position.y = Body_Sprite.getPosition().y + (-10*sin((Body_Sprite.getRotation()/180)*PI)) + (35*cos((Body_Sprite.getRotation()/180)*PI));
		Left_Foot_Sprite.setPosition(Left_Foot_Position);
	}

}