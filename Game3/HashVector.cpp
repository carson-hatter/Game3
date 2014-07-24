#include "HashVector.h"

sf::Vector2f HashVector::getVector()
{
	sf::Vector2f Vector_To_Return;

	Vector_To_Return.x = (rand() % int(Boundary.width)) + Boundary.left;
	Vector_To_Return.y = (rand() % int(Boundary.height)) + Boundary.top;

	return Vector_To_Return;
}

//float HashVector::getDuration()
//{
//	float to_return;
//
//	to_return = rand() % int(max_duration - min_duration);
//	to_return += min_duration;
//
//	return to_return;
//}

bool HashVector::isRotationInBounds(float test_rotation)
{
	float temp_c_c_w_boundary = c_c_w_boundary;

	while(c_w_boundary < temp_c_c_w_boundary)
	{
		temp_c_c_w_boundary -= 360;
		//test_rotation -= 360;
	}

	if((test_rotation <= c_w_boundary) && (test_rotation >= temp_c_c_w_boundary))
	{
		return true;
	}
	return false;
}

void HashVector::moveBoundary(float x, float y)
{
	Boundary.left += x;
	Boundary.top += y;
}

float HashVector::getRotation()
{
	float temp_c_c_w_boundary = c_c_w_boundary;

	if(c_w_boundary < c_c_w_boundary)
	{
		temp_c_c_w_boundary -= 360;
	}

	float boundary_difference = c_w_boundary - temp_c_c_w_boundary;

	float float_to_return = (rand() % int(boundary_difference)) + temp_c_c_w_boundary;
	if(float_to_return < 0)
	{
		float_to_return +=360;
	}

	return float_to_return;
}