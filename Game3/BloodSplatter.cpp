#include "BloodSplatter.h"

bool BloodSplatter::isExpired()
{
	if(expiration_time <= Expiration_Clock.getElapsedTime().asSeconds())
	{
		return true;
	}
	return false;
}
BloodSplatter::BloodSplatter(sf::Vector2f Victim_Position, sf::Vector2f Attacker_Position)
{
	expiration_time = 40;

	float x_diff = Victim_Position.x - Attacker_Position.x;
	float y_diff = Victim_Position.y - Attacker_Position.y;
	float theta = atan2(y_diff, x_diff);

	float new_hypotenuse = 25;
	float new_x_diff = new_hypotenuse * cos(theta);
	float new_y_diff = new_hypotenuse * sin(theta);

	float circle_radius, triangle_base, triangle_height;
	circle_radius = 10;
	triangle_base = circle_radius * 2;
	triangle_height = triangle_base * 3;
	Circle_Sprite.setRadius(circle_radius);
	Circle_Sprite.setFillColor(sf::Color::Red);
	Circle_Sprite.setOrigin(circle_radius, circle_radius);
	Circle_Sprite.setPosition(Victim_Position.x + new_x_diff, Victim_Position.y + new_y_diff);
	Triangle_Sprite.setPointCount(3);
	Triangle_Sprite.setPoint(0, sf::Vector2f(0,0));
	Triangle_Sprite.setPoint(1, sf::Vector2f(triangle_height, triangle_base / 2));
	Triangle_Sprite.setPoint(2, sf::Vector2f(0, triangle_base));
	Triangle_Sprite.setOrigin(0, triangle_base / 2);
	Triangle_Sprite.setPosition(Circle_Sprite.getPosition());
	Triangle_Sprite.setRotation(theta * 180 / 3.14);
	Triangle_Sprite.setFillColor(sf::Color::Red);


	unsigned int max_number_of_mist_drops = 5;
	unsigned int mist_sprite_radius = 5;
	Mist_Sprites.resize(rand() % max_number_of_mist_drops);
	for(unsigned int i = 0; i < Mist_Sprites.size(); i++)
	{
		float temp_x_diff = new_x_diff;
		float temp_y_diff = new_y_diff;

		float random_x_diff, random_y_diff;
		float max_vector_diff = 20;

		random_x_diff = rand() % int(max_vector_diff);
		random_y_diff = rand() % int(max_vector_diff);
		if((rand() % 2) == 0)
		{
			temp_x_diff -= random_x_diff;
		}
		else
		{
			temp_x_diff += random_x_diff;
		}
		if((rand() % 2) == 0)
		{
			temp_y_diff -= random_y_diff;
		}
		else
		{
			temp_y_diff += random_y_diff;
		}

		Mist_Sprites[i].setRadius(mist_sprite_radius);
		Mist_Sprites[i].setOrigin(mist_sprite_radius, mist_sprite_radius);
		Mist_Sprites[i].setPosition(Circle_Sprite.getPosition().x + temp_x_diff, Circle_Sprite.getPosition().y + temp_y_diff);
		Mist_Sprites[i].setFillColor(sf::Color::Red);
	}
}