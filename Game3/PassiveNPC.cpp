#include "PassiveNPC.h"

void PassiveNPC::chooseScript()
{
	if((Aggro_Clock.getElapsedTime().asSeconds() < aggro_time_limit) && (Pocket_Watch.getElapsedTime().asSeconds() >= aggro_time_limit))
	{
		fleeScript();
	}
	else
	{
		defaultScript();
	}
}

void PassiveNPC::defaultScript()
{
	if(Path_To_Destination.empty())
	{
		if(Current_Hash_Vector)
		{
			if(Default_Clock.getElapsedTime().asSeconds() > Current_Hash_Vector->getDuration())
			{
				Default_Clock.restart();

				unsigned int random_number = rand() % Hash_Vectors.size();

				Current_Hash_Vector = &Hash_Vectors.at(random_number);

				pathFinding(convertSFMLToDijkstras(Current_Hash_Vector->getVector()));
			}
		}
		else
		{
			unsigned int random_number = rand() % Hash_Vectors.size();

			Current_Hash_Vector = &Hash_Vectors.at(random_number);

			pathFinding(convertSFMLToDijkstras(Current_Hash_Vector->getVector()));
		}
	}

	Head_Sprite.setRotation(Body_Sprite.getRotation());
}

void PassiveNPC::fleeScript()
{
	if(Current_Hash_Vector)
	{
		Current_Hash_Vector = NULL;
	}

	if(Path_To_Destination.empty())
	{
		unsigned int random_number = rand() % Flee_Boxes.size();
		sf::Vector2f Random_Vector(Flee_Boxes[random_number].getVector());

		pathFinding(convertSFMLToDijkstras(Random_Vector));
	}
	Head_Sprite.setRotation(Body_Sprite.getRotation());
}

void PassiveNPC::determineRotation()
{
	if(Current_Hash_Vector)
	{
		if(Path_To_Destination.empty())
		{
			if(Current_Hash_Vector->isPointContained(Body_Sprite.getPosition()))
			{
				if(!Current_Hash_Vector->isRotationInBounds(Body_Sprite.getRotation()))
				{
					Body_Sprite.setRotation(Current_Hash_Vector->getRotation());
				}
			}
		}
	}
}

void PassiveNPC::pathFinding(unsigned int destination)
{
	Path_To_Destination.clear();
	std::vector<double> min_distance;
	std::vector<int> previous;
	DijkstraComputePaths(convertSFMLToDijkstras(Body_Sprite.getPosition()), *Adjacency_List, min_distance, previous);
	std::list<int> Temp = DijkstraGetShortestPathTo(destination, previous);
	unsigned int temp_size = Temp.size();
	for(unsigned int i = 0; i < temp_size; i++)
	{
		Path_To_Destination.push_back(convertDijkstrasToSFML(Temp.front()));
		Temp.pop_front();
	}
}

sf::Vector2f PassiveNPC::convertDijkstrasToSFML(unsigned int target)
{
	sf::Vector2i To_Be_Returned;
	To_Be_Returned.x = ((target % (int(Adj_List_Boundary.width) / DIJKSTRASSIZE)) * DIJKSTRASSIZE) + (DIJKSTRASSIZE / 2);
	To_Be_Returned.y = ((target / (int(Adj_List_Boundary.width) / DIJKSTRASSIZE)) * DIJKSTRASSIZE) + (DIJKSTRASSIZE / 2);

	To_Be_Returned.x += Adj_List_Boundary.left;
	To_Be_Returned.y += Adj_List_Boundary.top;

	return sf::Vector2f(To_Be_Returned);
}

unsigned int PassiveNPC::convertSFMLToDijkstras(sf::Vector2f Target)
{
	int row, column;

	Target.x -= Adj_List_Boundary.left;
	Target.y -= Adj_List_Boundary.top;

	row = Target.y / DIJKSTRASSIZE;
	column = Target.x / DIJKSTRASSIZE;
	row *= (Adj_List_Boundary.width / DIJKSTRASSIZE);

	return row + column;
}