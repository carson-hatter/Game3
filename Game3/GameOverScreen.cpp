#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(/*PreGameMenu* &Pre_Game_Menu*//*, int time_alive, int enemies_killed*/)
{
	//if(Pre_Game_Menu)
	//{
	//	delete Pre_Game_Menu;
	//}

	//Pre_Game_Menu = new PreGameMenu();

	Font = new sf::Font;
	Font->loadFromFile("cour.ttf");

	Background_Texture = new sf::Texture;
	Background_Texture->loadFromFile("game over screen background texture.jpg");

	Background.setPosition(0,0);
	Background.setSize(sf::Vector2f(1600,900));
	Background.setTexture(Background_Texture);

	Game_Over_Text.setFont(*Font);
	Game_Over_Text.setString("GAME OVER");
	Game_Over_Text.setCharacterSize(48);
	Game_Over_Text.setPosition(800 - (Game_Over_Text.getGlobalBounds().width / 2), 300);
	
	Thank_You_Text.setFont(*Font);
	Thank_You_Text.setString("Slim Charles thanks you for playing!");
	Thank_You_Text.setCharacterSize(24);
	Thank_You_Text.setPosition(800 - (Thank_You_Text.getGlobalBounds().width / 2), 400);

	Click_Anywhere_Text.setFont(*Font);
	Click_Anywhere_Text.setString("(click anywhere to continue)");
	Click_Anywhere_Text.setCharacterSize(16);
	Click_Anywhere_Text.setPosition(800 - (Click_Anywhere_Text.getGlobalBounds().width / 2), 500);

	minimum_time = 3;
}

bool GameOverScreen::eventHandling(sf::RenderWindow &Window)
{

	sf::Event Event;
	while(Window.pollEvent(Event))
	{
		if(Clock.getElapsedTime().asSeconds() > minimum_time)
		{			
			if((Event.type == sf::Event::MouseButtonReleased) || (Event.type == sf::Event::KeyReleased))
			{
				return true;
			}
		}
	}


	return false;
}

void GameOverScreen::drawEverything(sf::RenderWindow &Window)
{
	Window.clear();

	Window.setView(Window.getDefaultView());

	Window.draw(Background);
	Window.draw(Thank_You_Text);
	Window.draw(Click_Anywhere_Text);
	Window.draw(Game_Over_Text);
}