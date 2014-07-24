/*
* "GameOverScreen" is the user interface presented after Game::P_C has died.
* Instantiated in main.cpp.
*/
#pragma once

#include "PreGameMenu.h"
#include <SFML/Graphics.hpp>

class GameOverScreen
{
private: sf::Font *Font;

private: sf::Texture *Background_Texture;

private: sf::RectangleShape Background;

private: sf::Text Thank_You_Text;

private: sf::Text Game_Over_Text;

private: sf::Text Click_Anywhere_Text;

public: GameOverScreen();

/*Any key or mouse related event sends user to pre-game-menu*/
public: bool eventHandling(sf::RenderWindow&
			);

public: void drawEverything(sf::RenderWindow&
			);

private: sf::Clock Clock;

private: unsigned int minimum_time;
};