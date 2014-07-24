#include "ResidentialGrid.h"

void ResidentialGrid::drawEverything(sf::RenderWindow &Window)
{
	for(unsigned int i = 0; i < Floor_Tiles.size(); i++)
	{
		Window.draw(Floor_Tiles[i]);
	}
	for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
	{
		Window.draw(Tall_Collisions[i]);
	}
	for(unsigned int i = 0; i < Short_Collisions.size(); i++)
	{
		Window.draw(Short_Collisions[i]);
	}
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Window.draw(Passive_NPC_Family_Members[i].getLeftFootSprite());
		Window.draw(Passive_NPC_Family_Members[i].getRightFootSprite());
		Window.draw(Passive_NPC_Family_Members[i].getBodySprite());
		Window.draw(Passive_NPC_Family_Members[i].getHeadSprite());
	}

}

void ResidentialGrid::setPassiveNPCsAdjLists(std::vector<std::vector<Dijkstras::neighbor> >* Adj_List)
{
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Passive_NPC_Family_Members[i].setAdjList(Adj_List);
	}
}

void ResidentialGrid::restartAggroClocks()
{
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Passive_NPC_Family_Members[i].restartAggroClock();
	}	
}

void ResidentialGrid::passiveNPCsScripting()
{
	if(Passive_NPC_Family_Members.size() > 0)
	{
		Passive_NPC_Family_Members[family_members_vector_iterator].chooseScript();
	}
}

void ResidentialGrid::incrementPassiveNPCIterators()
{
	family_members_vector_iterator++;
	if(family_members_vector_iterator == Passive_NPC_Family_Members.size())
	{
		family_members_vector_iterator = 0;
	}	
}

void ResidentialGrid::updateCharacterSprites()
{
	//Passive_NPC_Family_Members[family_members_vector_iterator].updateCharacterSprite();
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Passive_NPC_Family_Members[i].updateCharacterSprite();
	}
}

void ResidentialGrid::moveCharacterSprites(sf::Time Frame_Time)
{
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Passive_NPC_Family_Members[i].movement(Frame_Time);
	}
}

void ResidentialGrid::determinePassiveNPCsRotations()
{
	for(unsigned int i = 0; i < Passive_NPC_Family_Members.size(); i++)
	{
		Passive_NPC_Family_Members[i].determineRotation();
	}
}
