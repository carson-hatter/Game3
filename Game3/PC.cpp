#include "PC.h"

void PC::movement(sf::Time Time_Per_Frame)
{
	sf::Vector2f Previous_PC_Position = Body_Sprite.getPosition();
	sf::Vector2f Movement_Vector (0,0);	
	
	if(!isStitching())
	{
		unsigned int temp_speed = speed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Movement_Vector.y = -(temp_speed*Time_Per_Frame.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Movement_Vector.x = temp_speed*Time_Per_Frame.asSeconds();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Movement_Vector.y = temp_speed*Time_Per_Frame.asSeconds();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Movement_Vector.x = -(temp_speed*Time_Per_Frame.asSeconds());
		}

		if(Movement_Vector.y < -max_movement_vector)
		{
			Movement_Vector.y = -max_movement_vector;
		}
		if(Movement_Vector.y > max_movement_vector)
		{
			Movement_Vector.y = max_movement_vector;
		}
		if(Movement_Vector.x < -max_movement_vector)
		{
			Movement_Vector.x = -max_movement_vector;
		}
		if(Movement_Vector.x > max_movement_vector)
		{
			Movement_Vector.x = max_movement_vector;
		}

		Body_Sprite.move(Movement_Vector);

		if((Movement_Vector.x != 0) || (Movement_Vector.y != 0))
		{
			if((Movement_Clock.getElapsedTime().asMilliseconds() % 500) < 250)
			{
				Sprite_Movement = WALKING1;
			}
			else
			{
				Sprite_Movement = WALKING2;
			}

		}
	}

	if((Movement_Vector.x == 0) && (Movement_Vector.y == 0))
	{
		Sprite_Movement = STANDING;
	}

	if((Current_Grid->shortCollisionsDetection(Body_Sprite.getPosition())) 
		|| 
		(Current_Grid->tallCollisionsDetection(Body_Sprite.getPosition()))
		||
		(Body_Sprite.getPosition().x < 0)
		||
		(Body_Sprite.getPosition().y < 0)
		||
		(Body_Sprite.getPosition().x > Map_Dimensions.x)
		||
		(Body_Sprite.getPosition().y > Map_Dimensions.y)
		)
	{
		Body_Sprite.setPosition(Previous_PC_Position);
	}

}

bool PC::isStitching()
{
	if((Stitching_Clock.getElapsedTime().asSeconds() < stitching_duration) && (Pocket_Watch.getElapsedTime().asSeconds() >= stitching_duration))
	{
		return true;
	}

	return false;
}

bool PC::stitching()
{
	if((is_bleeding) && (!isStitching()))
	{
		Stitching_Clock.restart();
		is_bleeding = false;
		return true;
	}
	return false;
}

bool PC::reloading()
{
	if((!isReloading()) && (bullets_in_clip < clip_size))
	{
		Reloading_Clock.restart();
		bullets_in_clip = clip_size;
		return true;
	}
	return false;
}

bool PC::attack(sf::Vector2f Target_Position, float &target_health)
{
	//if(bullets_in_clip > 0)
	//{
		//Attack_Clock.restart();
		//bullets_in_clip--;

		unsigned int max_distance = 4000;

		float angle_to_target, distance_to_target, x_diff, y_diff;
		x_diff = Target_Position.x - Body_Sprite.getPosition().x;
		y_diff = Target_Position.y - Body_Sprite.getPosition().y;
		distance_to_target = sqrt((x_diff * x_diff) + (y_diff * y_diff));
		angle_to_target = atan2(y_diff, x_diff) * 180 / 3.14;

		while(angle_to_target<0)
		{
			angle_to_target += 360;
		}
		while(angle_to_target >360)
		{
			angle_to_target -= 360;
		}

		if((Head_Sprite.getRotation() <= 350)&&(Head_Sprite.getRotation() >= 10))
		{
			if((distance_to_target <= max_distance) && (angle_to_target >= (Head_Sprite.getRotation() - 10))&&(angle_to_target<=(Head_Sprite.getRotation() + 10)))
			{
				if(Current_Grid->lineOfSight(Target_Position, Body_Sprite.getPosition()))
				{
					target_health -= weapon_damage;
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation() > 350)
		{
			float temp = Head_Sprite.getRotation() - 350;
			if((distance_to_target <= max_distance) && ((angle_to_target >= (Head_Sprite.getRotation() - 10)) || (angle_to_target <= temp)))
			{
				if(Current_Grid->lineOfSight(Target_Position, Body_Sprite.getPosition()))
				{
					target_health -= weapon_damage;
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation() < 10)
		{
			float temp = 360 - (10 - Head_Sprite.getRotation());
			if((distance_to_target <= max_distance) && ((angle_to_target <= (Head_Sprite.getRotation() + 10)) || (angle_to_target >= temp)))
			{
				if(Current_Grid->lineOfSight(Target_Position, Body_Sprite.getPosition()))
				{
					target_health -= weapon_damage;
					return true;
				}
			}
		}
	//	return true;
	////}
	return false;
}

bool PC::isReloading()
{
	if((Reloading_Clock.getElapsedTime().asSeconds() < reload_duration) && (Pocket_Watch.getElapsedTime().asSeconds() >= reload_duration))
	{
		return true;
	}

	return false;
}

bool PC::fieldOfView(sf::Vector2f Target)
{
	if(Current_Grid->lineOfSight(Target, Body_Sprite.getPosition()))
	{
		float angle_to_target, distance_to_target, x_diff, y_diff;
		x_diff = Target.x - Body_Sprite.getPosition().x;
		y_diff = Target.y - Body_Sprite.getPosition().y;
		distance_to_target = sqrt((x_diff * x_diff) + (y_diff * y_diff));
		angle_to_target = atan2(y_diff, x_diff) * 180 / 3.14;

		unsigned int max_distance = 4000;

		unsigned int field_of_view_half = field_of_view / 2;

		if(angle_to_target<0)
		{
			angle_to_target += 360;
		}

		if((Head_Sprite.getRotation() <= (360 - field_of_view_half/*280*/)) && (Head_Sprite.getRotation() >= field_of_view_half/*80*/))
		{
			if((distance_to_target <= max_distance) && (angle_to_target>=(Head_Sprite.getRotation() - field_of_view_half))&&(angle_to_target<=(Head_Sprite.getRotation() + field_of_view_half)))
			{
				{
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation() > 360 - field_of_view_half)
		{
			float temp = Head_Sprite.getRotation() - (360 - field_of_view_half);
			if((distance_to_target <= max_distance) && ((angle_to_target >= (Head_Sprite.getRotation() - field_of_view_half)) || (angle_to_target <= temp)))
			{
				{
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation() < field_of_view_half)
		{
			float temp = 360 - (field_of_view_half - Head_Sprite.getRotation());
			if((distance_to_target <= max_distance) && ((angle_to_target <= (Head_Sprite.getRotation() + field_of_view_half)) || (angle_to_target >= temp)))
			{
				{
					return true;
				}
			}
		}
	}

	return false;
}

void PC::setHeadRotation()
{
	Head_Sprite.setRotation(Body_Sprite.getRotation());
}

void PC::switchCurrentGrid()
{
	if(!Current_Grid->getBoundary().contains(Body_Sprite.getPosition()))
	{
		Grid *Temp = Current_Grid;

		if(Current_Grid->North_Grid)
		{
			if(Current_Grid->North_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->North_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->Northeast_Grid)
		{
			if(Current_Grid->Northeast_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Northeast_Grid;

				/*return;*/
			}
		}
		
		if(Current_Grid->East_Grid)
		{
			if(Current_Grid->East_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->East_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->Southeast_Grid)
		{
			if(Current_Grid->Southeast_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Southeast_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->South_Grid)
		{
			if(Current_Grid->South_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->South_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->Southwest_Grid)
		{
			if(Current_Grid->Southwest_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Southwest_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->West_Grid)
		{
			if(Current_Grid->West_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->West_Grid;

				/*return;*/
			}
		}

		if(Current_Grid->Northwest_Grid)
		{
			if(Current_Grid->Northwest_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Northwest_Grid;

				/*return;*/
			}
		}

		if(Current_Grid != Temp)
		{
			Temp->pauseAllCivClocks();
			Current_Grid->resumeAllCivClocks();
			Temp->stopBackgroundSFX();
			//Current_Grid->resumeAllCivPocketWatches();
		}
	}
}