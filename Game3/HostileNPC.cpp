#include "HostileNPC.h"

void HostileNPC::switchCurrentGrid()
{
	if(!Current_Grid->getBoundary().contains(Body_Sprite.getPosition()))
	{
		if(Current_Grid->North_Grid)
		{
			if(Current_Grid->North_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->North_Grid;

				return;
			}
		}

		if(Current_Grid->Northeast_Grid)
		{
			if(Current_Grid->Northeast_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Northeast_Grid;

				return;
			}
		}
		
		if(Current_Grid->East_Grid)
		{
			if(Current_Grid->East_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->East_Grid;

				return;
			}
		}

		if(Current_Grid->Southeast_Grid)
		{
			if(Current_Grid->Southeast_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Southeast_Grid;

				return;
			}
		}

		if(Current_Grid->South_Grid)
		{
			if(Current_Grid->South_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->South_Grid;

				return;
			}
		}

		if(Current_Grid->Southwest_Grid)
		{
			if(Current_Grid->Southwest_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Southwest_Grid;

				return;
			}
		}

		if(Current_Grid->West_Grid)
		{
			if(Current_Grid->West_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->West_Grid;

				return;
			}
		}

		if(Current_Grid->Northwest_Grid)
		{
			if(Current_Grid->Northwest_Grid->getBoundary().contains(Body_Sprite.getPosition()))
			{
				Current_Grid = Current_Grid->Northwest_Grid;

				return;
			}
		}

	}
}

bool HostileNPC::isBloodDropVisible(sf::Vector2f P_C_Position)
{
	bool sentinel = false;

	for(unsigned int i = 0; i < Blood_Trail->getBloodDropVectorSize(); i++)
	{
		if(fieldOfView(P_C_Position))
		{
			sentinel = true;
		}
	}

	return sentinel;
}

void HostileNPC::pathFinding(unsigned int destination)
{
	Path_To_Destination.clear();
	std::vector<double> min_distance;
	std::vector<int> previous;
	DijkstraComputePaths(convertSFMLToDijkstras(Body_Sprite.getPosition()), *(Current_Grid->getAdjList()), min_distance, previous);
	std::list<int> Temp = DijkstraGetShortestPathTo(destination, previous);
	unsigned int temp_size = Temp.size();
	for(unsigned int i = 0; i < temp_size; i++)
	{
		Path_To_Destination.push_back(convertDijkstrasToSFML(Temp.front()));
		Temp.pop_front();
	}
}

sf::Vector2f HostileNPC::convertDijkstrasToSFML(unsigned int target)
{
	sf::Vector2i To_Be_Returned;
	To_Be_Returned.x = ((target % (int(Current_Grid->getAdjListBoundary().width) / DIJKSTRASSIZE)) * DIJKSTRASSIZE) + (DIJKSTRASSIZE / 2);
	To_Be_Returned.y = ((target / (int(Current_Grid->getAdjListBoundary().width) / DIJKSTRASSIZE)) * DIJKSTRASSIZE) + (DIJKSTRASSIZE / 2);

	To_Be_Returned.x += Current_Grid->getAdjListBoundary().left;
	To_Be_Returned.y += Current_Grid->getAdjListBoundary().top;

	return sf::Vector2f(To_Be_Returned);
}

unsigned int HostileNPC::convertSFMLToDijkstras(sf::Vector2f Target)
{
	int row, column;

	Target.x -= Current_Grid->getAdjListBoundary().left;
	Target.y -= Current_Grid->getAdjListBoundary().top;

	row = Target.y / DIJKSTRASSIZE;
	column = Target.x / DIJKSTRASSIZE;
	row *= (Current_Grid->getAdjListBoundary().width / DIJKSTRASSIZE);

	return row + column;
}

bool HostileNPC::fieldOfView(sf::Vector2f Target)
{
	if(Current_Grid->lineOfSight(Target, Body_Sprite.getPosition()))
	{
		unsigned int max_distance = 450;

		float angle_to_target, distance_to_target, x_diff, y_diff;
		x_diff = Target.x - Body_Sprite.getPosition().x;
		y_diff = Target.y - Body_Sprite.getPosition().y;
		distance_to_target = sqrt((x_diff * x_diff) + (y_diff * y_diff));
		angle_to_target = atan2(y_diff, x_diff) * 180 / 3.14;

		if(angle_to_target<0)
		{
			angle_to_target += 360;
		}

		if((Head_Sprite.getRotation()<= 280)&&(Head_Sprite.getRotation()>=80))
		{
			if((distance_to_target<=max_distance)&&(angle_to_target>=(Head_Sprite.getRotation()-80))&&(angle_to_target<=(Head_Sprite.getRotation()+80)))
			{
				{
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation()>280)
		{
			float temp = Head_Sprite.getRotation()-280;
			if((distance_to_target<=max_distance)&&((angle_to_target>=(Head_Sprite.getRotation()-80))||(angle_to_target<=temp)))
			{
				{
					return true;
				}
			}
		}
		else if(Head_Sprite.getRotation()<80)
		{
			float temp = 360-(80-Head_Sprite.getRotation());
			if((distance_to_target<=max_distance)&&((angle_to_target<=(Head_Sprite.getRotation()+80))||(angle_to_target>=temp)))
			{
				{
					return true;
				}
			}
		}
	}

	return false;
}

void HostileNPC::constructDeathSprite()
{
	death_sprite_constructed = true;

	Death_Sprite.resize(7);

	Death_Sprite[0].setPointCount(4); // BODY
	Death_Sprite[0].setPoint(0 , sf::Vector2f(0,0));
	Death_Sprite[0].setPoint(1, sf::Vector2f(60,0));
	Death_Sprite[0].setPoint(2, sf::Vector2f(60,80));
	Death_Sprite[0].setPoint(3, sf::Vector2f(0,80));
	Death_Sprite[0].setOrigin(Death_Sprite[0].getPoint(0));
	Death_Sprite[0].setPosition(Body_Sprite.getPosition());
	Death_Sprite[0].setTexture(Body_Sprite.getTexture());
	Death_Sprite[0].setTextureRect(sf::IntRect(Body_Sprite.getTextureRect().left, Body_Sprite.getTextureRect().top + Body_Sprite.getTextureRect().height, Body_Sprite.getTextureRect().width, Body_Sprite.getTextureRect().height));

	Death_Sprite_Head.setRadius(15);
	Death_Sprite_Head.setOrigin(sf::Vector2f(Death_Sprite_Head.getRadius(), Death_Sprite_Head.getRadius()));
	Death_Sprite_Head.setPosition(Death_Sprite[0].getPosition().x + (Death_Sprite[0].getGlobalBounds().width / 2), Death_Sprite[0].getPosition().y - Death_Sprite_Head.getRadius());
	Death_Sprite_Head.setTexture(Head_Sprite.getTexture());
	Death_Sprite_Head.setTextureRect(Head_Sprite.getTextureRect());

	Death_Sprite[1].setPointCount(4); // RIGHT ARM
	Death_Sprite[1].setPoint(0 , sf::Vector2f(0,20));
	Death_Sprite[1].setPoint(1, sf::Vector2f(80,0));
	Death_Sprite[1].setPoint(2, sf::Vector2f(80,10));
	Death_Sprite[1].setPoint(3, sf::Vector2f(0,30));
	Death_Sprite[1].setOrigin(Death_Sprite[1].getPoint(0));
	Death_Sprite[1].setPosition(sf::Vector2f(Death_Sprite[0].getPoint(1).x + Death_Sprite[0].getPosition().x, Death_Sprite[0].getPoint(1).y + Death_Sprite[0].getPosition().y));
	Death_Sprite[1].setTexture(Right_Arm_Sprite.getTexture());
	Death_Sprite[1].setTextureRect(Right_Arm_Sprite.getTextureRect());

	Death_Sprite[2].setPointCount(4); // LEFT ARM
	Death_Sprite[2].setPoint(0 , sf::Vector2f(0,30));
	Death_Sprite[2].setPoint(1, sf::Vector2f(80,0));
	Death_Sprite[2].setPoint(2, sf::Vector2f(80,10));
	Death_Sprite[2].setPoint(3, sf::Vector2f(0,40));
	Death_Sprite[2].setOrigin(Death_Sprite[2].getPoint(1));
	Death_Sprite[2].setPosition(Death_Sprite[0].getPosition());
	Death_Sprite[2].setTexture(Right_Arm_Sprite.getTexture());
	Death_Sprite[2].setTextureRect(sf::IntRect(Right_Arm_Sprite.getTextureRect().left + Right_Arm_Sprite.getTextureRect().width, Right_Arm_Sprite.getTextureRect().top + Right_Arm_Sprite.getTextureRect().height, -Right_Arm_Sprite.getTextureRect().width, -Right_Arm_Sprite.getTextureRect().height) /*Right_Arm_Sprite.getTextureRect()*/);

	Death_Sprite[3].setPointCount(4); //left leg
	Death_Sprite[3].setPoint(0, sf::Vector2f(0,0));
	Death_Sprite[3].setPoint(1, sf::Vector2f(Death_Sprite[0].getLocalBounds().width / 2, 0));
	Death_Sprite[3].setPoint(2, sf::Vector2f(Death_Sprite[3].getPoint(1).x / 2, Death_Sprite[0].getLocalBounds().height * (5/4)));
	Death_Sprite[3].setPoint(3, sf::Vector2f(0, Death_Sprite[3].getPoint(2).y));
	Death_Sprite[3].setOrigin(Death_Sprite[3].getPoint(0));
	Death_Sprite[3].setPosition(Death_Sprite[0].getPoint(3).x + Death_Sprite[0].getPosition().x, Death_Sprite[0].getPoint(3).y + Death_Sprite[0].getPosition().y);
	Death_Sprite[3].setTexture(Death_Sprite[0].getTexture());
	Death_Sprite[3].setTextureRect(Death_Sprite[0].getTextureRect());

	Death_Sprite[4].setPointCount(4); //right leg
	Death_Sprite[4].setPoint(0, sf::Vector2f(0,0));
	Death_Sprite[4].setPoint(1, sf::Vector2f(Death_Sprite[0].getLocalBounds().width / 2, 0));
	Death_Sprite[4].setPoint(2, sf::Vector2f(Death_Sprite[4].getPoint(1).x, Death_Sprite[0].getLocalBounds().height * (5/4)));
	Death_Sprite[4].setPoint(3, sf::Vector2f(Death_Sprite[4].getPoint(1).x / 2, Death_Sprite[4].getPoint(2).y));
	Death_Sprite[4].setOrigin(Death_Sprite[4].getPoint(0));
	Death_Sprite[4].setPosition(Death_Sprite[0].getPoint(3).x + Death_Sprite[0].getPosition().x + (Death_Sprite[0].getLocalBounds().width / 2), Death_Sprite[0].getPoint(3).y + Death_Sprite[0].getPosition().y);
	Death_Sprite[4].setTexture(Death_Sprite[0].getTexture());
	Death_Sprite[4].setTextureRect(Death_Sprite[0].getTextureRect());

	Death_Sprite[5].setPointCount(5); //left foot
	Death_Sprite[5].setPoint(0, sf::Vector2f(25 - Death_Sprite[3].getPoint(2).x, 0));
	Death_Sprite[5].setPoint(1, sf::Vector2f(25, 0));
	Death_Sprite[5].setPoint(2, sf::Vector2f(25, 8));
	Death_Sprite[5].setPoint(3, sf::Vector2f(0, 8));
	Death_Sprite[5].setPoint(4, sf::Vector2f(0, 4));
	Death_Sprite[5].setOrigin(Death_Sprite[5].getPoint(0));
	Death_Sprite[5].setPosition(sf::Vector2f(Death_Sprite[3].getPoint(3).x + Death_Sprite[3].getPosition().x, Death_Sprite[3].getPoint(3).y + Death_Sprite[3].getPosition().y));
	Death_Sprite[5].setTexture(Left_Foot_Sprite.getTexture());
	Death_Sprite[5].setTextureRect(Left_Foot_Sprite.getTextureRect());

	Death_Sprite[6].setPointCount(5); //right foot
	Death_Sprite[6].setPoint(0, sf::Vector2f(0,0));
	Death_Sprite[6].setPoint(1, sf::Vector2f(25 - Death_Sprite[3].getPoint(2).x, 0));
	Death_Sprite[6].setPoint(2, sf::Vector2f(25, 4));
	Death_Sprite[6].setPoint(3, sf::Vector2f(25, 8));
	Death_Sprite[6].setPoint(4, sf::Vector2f(0, 8));
	Death_Sprite[6].setOrigin(Death_Sprite[6].getPoint(0));
	Death_Sprite[6].setPosition(sf::Vector2f(Death_Sprite[4].getPoint(3).x + Death_Sprite[4].getPosition().x, Death_Sprite[4].getPoint(3).y + Death_Sprite[4].getPosition().y));
	Death_Sprite[6].setTexture(Left_Foot_Sprite.getTexture());
	Death_Sprite[6].setTextureRect(Left_Foot_Sprite.getTextureRect());
}