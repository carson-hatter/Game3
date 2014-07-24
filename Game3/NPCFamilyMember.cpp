#include "NPCFamilyMember.h"

void NPCFamilyMember::chooseScript(Character *Suspect)
{
	//if(Aggro_Clock.getElapsedTime().asSeconds() < aggro_time_limit)
	//{
	//	fleeScript(Suspect);
	//}
	//else
	//{
		wanderScript();
	//}
}

void NPCFamilyMember::fleeScript(Character *Suspect)
{

}

void NPCFamilyMember::wanderScript()
{
	if(Wander_Clock.getElapsedTime().asSeconds() >= standing_still_time_limit)
	{
	//	if(Current_Hash_Vector)
	//	{
	//		if(Current_Hash_Vector->occupied)
	//		{
	//			Current_Hash_Vector->occupied = false;
	//		}
	//	}

	//	unsigned int random_number = rand() % Current_Grid->Family_Member_Hash_Vectors.size();

	//	if(!Current_Grid->Family_Member_Hash_Vectors[random_number].occupied)
	//	{
	//		Current_Hash_Vector = &Current_Grid->Family_Member_Hash_Vectors[random_number];
	//		Current_Hash_Vector->occupied = true;
	//	}
	//	else
	//	{
	//		for(unsigned int i = 0; i < Current_Grid->Family_Member_Hash_Vectors.size(); i++)
	//		{
	//			if(!Current_Grid->Family_Member_Hash_Vectors[i].occupied)
	//			{
	//				Current_Hash_Vector = &Current_Grid->Family_Member_Hash_Vectors[random_number];
	//				Current_Hash_Vector->occupied = true;					
	//			}
	//		}
	//	}
	}
}