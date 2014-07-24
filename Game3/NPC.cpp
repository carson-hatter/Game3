#include "NPC.h"

void NPC::movement(sf::Time Time_Per_Frame)
{
	if(!isDead())
	{
		if(!Path_To_Destination.empty())
		{
			sf::Vector2f Target_Position(/*convertDijkstrasToSFML(*/Path_To_Destination.front()/*)*/);
			sf::Vector2f Movement_Vector(0,0);

			float theta, x_diff, y_diff;
			x_diff = Target_Position.x - Body_Sprite.getPosition().x;
			y_diff = Target_Position.y - Body_Sprite.getPosition().y;

			float temp_speed = speed * Time_Per_Frame.asSeconds();

			theta = atan2(y_diff, x_diff);

			Movement_Vector.y = temp_speed * sin(theta);
			Movement_Vector.x = temp_speed * cos(theta);

			//float max_movement_vector = 5;

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

			Body_Sprite.setRotation(theta * 180 / 3.14);
			
			Body_Sprite.move(Movement_Vector.x, Movement_Vector.y);

			if((abs(Target_Position.y - Body_Sprite.getPosition().y) < max_movement_vector) && ((abs(Target_Position.x - Body_Sprite.getPosition().x) < max_movement_vector)))
			{
				Body_Sprite.setPosition(/*convertDijkstrasToSFML(*/Path_To_Destination.front()/*)*/);
				Path_To_Destination.erase(Path_To_Destination.begin());
			}

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
			else
			{
				Sprite_Movement = STANDING;
			}
		}
		else
		{
			Sprite_Movement = STANDING;
		}
	}

}

bool NPC::isAggro()
{
	if(Aggro_Clock.getElapsedTime().asSeconds() < aggro_time_limit)
	{
		return true;
	}
	return false;
}