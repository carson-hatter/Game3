#include "BloodTrail.h"

BloodTrail::BloodTrail()
{
	
}

void BloodTrail::eraseExpiredBloodDrops()
{
	for(unsigned int i = 0; i < Blood_Drops.size(); i++)
	{
		if(Blood_Drops[i].isExpired())
		{
			Blood_Drops.erase(Blood_Drops.begin() + i);
		}
	}	
}

void BloodTrail::addBloodDrops(sf::Vector2f P_C_Position)
{
	unsigned int min_distance = 900;

	bool sentinel = true;

	for(unsigned int i = 0; i < Blood_Drops.size(); i++)
	{
		float x_diff, y_diff, distance;
		x_diff = P_C_Position.x - Blood_Drops[i].getSprite().getPosition().x;
		x_diff *= x_diff;
		y_diff = P_C_Position.y - Blood_Drops[i].getSprite().getPosition().y;
		y_diff *= y_diff;
		distance = sqrt(x_diff + y_diff);

		if(distance <= min_distance)
		{
			sentinel = false;
		}
	}

	if(sentinel)
	{
		Blood_Drops.push_back(BloodDrop(P_C_Position));
	}
}