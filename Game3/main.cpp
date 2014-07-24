#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "PreGameMenu.h"
#include "GameOverScreen.h"
	
int main()
{
	srand(time(NULL));

    sf::RenderWindow Window(sf::VideoMode(1600, 900), "Game 3");

	PreGameMenu *Pre_Game_Menu = new PreGameMenu();

	Game *Game_ = NULL;

	GameOverScreen *Game_Over_Screen = NULL;

	sf::Clock Frame_Clock;

    while (Window.isOpen())
    {
		sf::Time Time_Per_Frame = Frame_Clock.restart();

		if(Pre_Game_Menu)
		{
			Pre_Game_Menu->playMusic();
			Pre_Game_Menu->eventHandling(Window, Game_);
			Pre_Game_Menu->drawEverything(Window);
		}
		
		if(Game_)
		{
			if(Pre_Game_Menu)
			{
				delete Pre_Game_Menu;
				Pre_Game_Menu = NULL;
			}

			Game_->spawnHostileNPCs();
			Game_->buildDeathSprites();
			Game_->processBloodTrail();
			Game_->pcRotation(Window.mapPixelToCoords(sf::Mouse::getPosition(Window), Window.getView()));
			Game_->eventHandling(Window);
			Game_->npcScripting();
			Game_->moveCharacterSprites(Time_Per_Frame);
			Game_->incrementNPCIterators();
			Game_->updateHUD();
			Game_->eraseExpiredBloodSplatters();
			Game_->regenPCHealth(Time_Per_Frame);
			Game_->playGridSFX();
			Game_->drawEverything(Window);

			if(Game_->isGameOver())
			{
				delete Game_;
				Game_ = NULL;
				Game_Over_Screen = new GameOverScreen();
			}
		}

		if(Game_Over_Screen)
		{
			Game_Over_Screen->drawEverything(Window);

			if(Game_Over_Screen->eventHandling(Window))
			{
				delete Game_Over_Screen;
				Game_Over_Screen = NULL;
				Pre_Game_Menu = new PreGameMenu();
			}
		}

        Window.display();
    }

    return 0;
}