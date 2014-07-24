/*
* "HashVector" serves hostile and passive npc's by defining where they
* can walk to, given they aren't aggravated. When getting rotation or
* vector coordinates, a random number is generated within certain
* parameters.
* Instantiated in "Grid".
*/
#pragma once

#include <SFML/Graphics.hpp>

class HashVector
{
private: sf::FloatRect Boundary;

public: sf::FloatRect getBoundary(){return Boundary;}

public: void moveBoundary(float, //x
			float //y
			);

public: bool isPointContained(sf::Vector2f P){if(Boundary.contains(P)){return true;}return false;}

/*clock wise limit for getRotation()*/
private: float c_w_boundary;

/*counter clock wise limit for getRotation()*/
private: float c_c_w_boundary;

public: bool isRotationInBounds(float
			);

public: float getRotation();

public: sf::Vector2f getVector();

public: HashVector()
		{};

public: HashVector(sf::FloatRect Boundary_, float c_c_w_boundary_, float c_w_boundary_, float min_duration, float max_duration)
		{
			Boundary = Boundary_;
			c_c_w_boundary = c_c_w_boundary_;
			c_w_boundary = c_w_boundary_;
			duration = (rand() % int(max_duration - min_duration)) + min_duration;
		}

public: HashVector(sf::FloatRect Boundary_)
		{
			Boundary = Boundary_;
			c_c_w_boundary = 0;
			c_w_boundary = 0;
			duration = 0;
		}


private: float duration;

public: float getDuration(){return duration;}
};