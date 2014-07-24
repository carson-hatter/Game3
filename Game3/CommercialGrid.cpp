#include "CommercialGrid.h"

sf::RectangleShape CommercialGrid::buildWall(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,100,100));

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildDiningTable(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setPosition(Top_Left);
	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,100,100));

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildExpoTable(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setPosition(Top_Left);
	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(100,0,100,100));

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildGrill(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setPosition(Top_Left);
	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(200,0,100,100));

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildChair(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	
	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setOrigin(To_Return.getSize().x / 2, To_Return.getSize().y / 2);
	To_Return.setPosition(Top_Left.x + To_Return.getOrigin().x , Top_Left.y + To_Return.getOrigin().y);
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,100,100));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildToilet(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setOrigin(To_Return.getSize().x / 2, To_Return.getSize().y / 2);
	To_Return.setPosition(Top_Left.x + To_Return.getOrigin().x , Top_Left.y + To_Return.getOrigin().y);
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(100,0,100,100));
	To_Return.setRotation(rotation);

	return To_Return;
}
sf::RectangleShape CommercialGrid::buildSink(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &T_C_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setOrigin(To_Return.getSize().x / 2, To_Return.getSize().y / 2);
	To_Return.setPosition(Top_Left.x + To_Return.getOrigin().x , Top_Left.y + To_Return.getOrigin().y);
	To_Return.setTexture(&T_C_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(300,0,100,100));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape CommercialGrid::buildTestFloorTile(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right)
{
	sf::RectangleShape To_Return;

	To_Return.setPosition(Top_Left);
	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setFillColor(sf::Color::Blue);

	return To_Return;
}