#include "NPCAssassin.h"

bool/*void*/ NPCAssassin::chooseScript(PC &Suspect)
{
	if(!isDead())
	{
		if((Aggro_Clock.getElapsedTime().asSeconds() < aggro_time_limit) /*&& (Pocket_Watch.getElapsedTime().asSeconds() >= aggro_time_limit)*/)
		{
			if(fieldOfView(Suspect.getBodySprite().getPosition()))
			{
				if(attackScript(Suspect))
				{
					return true;
				}
			}
			else
			{
				huntScript(Suspect);
			}
		}
		else
		{
			searchScript(Suspect.getBodySprite().getPosition());
		}
	}

	return false;
}

bool/*void*/ NPCAssassin::attackScript(PC &Suspect)
{
	if(!Path_To_Destination.empty())
	{
		Path_To_Destination.clear();
	}

	characterRotation(Suspect.getBodySprite().getPosition());
	
	if(Attack_Clock.getElapsedTime().asSeconds() > 3)
	{
		Aggro_Clock.restart();

		Suspect.health -= weapon_damage;
		Attack_Clock.restart();

		if(!Suspect.is_bleeding)
		{
			if(rand() % 5 == 0)
			{
				Suspect.is_bleeding = true;
			}
		}

		return true;
	}

	Head_Sprite.setRotation(Body_Sprite.getRotation());

	return false;
}

void NPCAssassin::huntScript(PC Suspect)
{
	if(Path_To_Destination.empty())
	{
		if((Current_Grid == Suspect.Current_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->North_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->Northeast_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->Northwest_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->South_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->Southeast_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->Southwest_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->West_Grid)
			||
			(Current_Grid == Suspect.Current_Grid->East_Grid)
			)
		{
			pathFinding(convertSFMLToDijkstras(Suspect.getBodySprite().getPosition()));

			for(unsigned int i = 0; i < Path_To_Destination.size() / 2; i++)
			{
				Path_To_Destination.pop_back();
			}
		}
	}
	if(isBloodDropVisible(Suspect.getBodySprite().getPosition()))
	{
		speed = jogging_speed;
		Aggro_Clock.restart();
	}
	else
	{
		speed = walking_speed;
	}


	Head_Sprite.setRotation(Body_Sprite.getRotation());
}

void NPCAssassin::searchScript(sf::Vector2f Suspect_Position)
{
	speed = walking_speed;

	if(fieldOfView(Suspect_Position))
	{
		restartAggroClock();
		return;
	}

	if(Path_To_Destination.empty())
	{
		unsigned int random_number = rand() % 4;

		if((random_number == 0) && (Current_Grid->North_Grid))
		{
			if(Current_Grid->North_Grid->Assassin_Hash_Vectors.size() > 0)
			{
				random_number = rand() % Current_Grid->North_Grid->Assassin_Hash_Vectors.size();
				pathFinding(convertSFMLToDijkstras(Current_Grid->North_Grid->Assassin_Hash_Vectors[random_number].getVector()));
			}
		}
		else if((random_number == 1) && (Current_Grid->South_Grid))
		{
			if(Current_Grid->South_Grid->Assassin_Hash_Vectors.size() > 0)
			{
				random_number = rand() % Current_Grid->South_Grid->Assassin_Hash_Vectors.size();
				pathFinding(convertSFMLToDijkstras(Current_Grid->South_Grid->Assassin_Hash_Vectors[random_number].getVector()));
			}
		}
		else if((random_number == 2) && (Current_Grid->East_Grid))
		{
			if(Current_Grid->East_Grid->Assassin_Hash_Vectors.size() > 0)
			{
				random_number = rand() % Current_Grid->East_Grid->Assassin_Hash_Vectors.size();
				pathFinding(convertSFMLToDijkstras(Current_Grid->East_Grid->Assassin_Hash_Vectors[random_number].getVector()));
			}
		}
		else if((random_number == 3) && (Current_Grid->West_Grid))
		{
			if(Current_Grid->West_Grid->Assassin_Hash_Vectors.size() > 0)
			{
				random_number = rand() % Current_Grid->West_Grid->Assassin_Hash_Vectors.size();
				pathFinding(convertSFMLToDijkstras(Current_Grid->West_Grid->Assassin_Hash_Vectors[random_number].getVector()));
			}
		}
	}

	Head_Sprite.setRotation(Body_Sprite.getRotation());
}