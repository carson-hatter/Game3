#include "PreGameMenu.h"

void PreGameMenu::eventHandling(sf::RenderWindow &Window, Game* &Game_)
{
	sf::Event Event;
	
	while(Window.pollEvent(Event))
	{
        if (Event.type == sf::Event::Closed)
		{
			Window.close();
		}

		if(Event.type == sf::Event::MouseButtonReleased)
		{
			if(Event.mouseButton.button == sf::Mouse::Left)
			{
				std::vector<std::vector<ClickableText> > *Next_Page = NULL;

				for(unsigned int i = 0; i < Current_Page->size(); i++)
				{
					for(unsigned int j = 0; j < Current_Page->at(i).size(); j++)
					{
						if(Current_Page->at(i)[j].Text.getGlobalBounds().contains(Window.mapPixelToCoords/*sf::Vector2f*/(sf::Mouse::getPosition(Window))))
						{
							if(Current_Page->at(i)[j].new_game)
							{
								/*User wants to play the game*/
								if(Game_)
								{
									delete Game_;
									Game_ = NULL;
								}

								Game_ = new Game(Window);

								Main_Menu_Music.stop();

							}
							if(Current_Page->at(i)[j].Next_Page)
							{
								/*User wants to see different page*/
								Next_Page = Current_Page->at(i)[j].Next_Page;
							}
						}
					}
				}
				
				if(Next_Page)
				{
					Current_Page = Next_Page;
				}
			}
		}
	}
}

PreGameMenu::PreGameMenu()
{
	Main_Menu_Music_Buffer.loadFromFile("main_menu_music.aiff");
	Main_Menu_Music.setBuffer(Main_Menu_Music_Buffer);
	Main_Menu_Music.setVolume(67);

	Font = new sf::Font;
	Font->loadFromFile("cour.ttf");

	Background_Texture = new sf::Texture;
	Background_Texture->loadFromFile("background_texture.jpg");
	Background.setTexture(Background_Texture);
	Background.setPosition(0,0);
	Background.setSize(sf::Vector2f(1600,900));

	Current_Page = &Title_Page;

	Title_Page.resize(1);
	Title_Page[0].resize(12);
	
	Title_Page[0][0].new_game = false;
	Title_Page[0][0].Next_Page = NULL;
	Title_Page[0][0].Text.setString("The Labyrinth");
	Title_Page[0][0].Text.setCharacterSize(72);
	Title_Page[0][0].Text.setPosition(0,0);
	
	Title_Page[0][1].new_game = false;
	Title_Page[0][1].Next_Page = NULL;
	Title_Page[0][1].Text.setCharacterSize(48);
	Title_Page[0][1].Text.setString("Welcome to my nightmare. You'll");
	Title_Page[0][1].Text.setPosition(0, Title_Page[0][0].Text.getPosition().y + Title_Page[0][0].Text.getCharacterSize());
	
	Title_Page[0][2].new_game = false;
	Title_Page[0][2].Next_Page = NULL;
	Title_Page[0][2].Text.setCharacterSize(48);
	Title_Page[0][2].Text.setString("wander aimlessly through a town.");
	Title_Page[0][2].Text.setPosition(0, Title_Page[0][1].Text.getPosition().y + Title_Page[0][1].Text.getCharacterSize());
	
	Title_Page[0][3].new_game = false;
	Title_Page[0][3].Next_Page = NULL;
	Title_Page[0][3].Text.setCharacterSize(48);
	Title_Page[0][3].Text.setString("You'll find no pleasant suburbs,");
	Title_Page[0][3].Text.setPosition(0, Title_Page[0][2].Text.getPosition().y + Title_Page[0][2].Text.getCharacterSize());
	
	Title_Page[0][4].new_game = false;
	Title_Page[0][4].Next_Page = NULL;
	Title_Page[0][4].Text.setCharacterSize(48);
	Title_Page[0][4].Text.setString("no open streets or sidewalks...");
	Title_Page[0][4].Text.setPosition(0, Title_Page[0][3].Text.getPosition().y + Title_Page[0][3].Text.getCharacterSize());
	
	Title_Page[0][5].new_game = false;
	Title_Page[0][5].Next_Page = NULL;
	Title_Page[0][5].Text.setCharacterSize(48);
	Title_Page[0][5].Text.setString("only alleyways, heartless");
	Title_Page[0][5].Text.setPosition(0, Title_Page[0][4].Text.getPosition().y + Title_Page[0][4].Text.getCharacterSize());
	
	Title_Page[0][6].new_game = false;
	Title_Page[0][6].Next_Page = NULL;
	Title_Page[0][6].Text.setCharacterSize(48);
	Title_Page[0][6].Text.setString("commerical districts, and some-");
	Title_Page[0][6].Text.setPosition(0, Title_Page[0][5].Text.getPosition().y + Title_Page[0][5].Text.getCharacterSize());
	
	Title_Page[0][7].new_game = false;
	Title_Page[0][7].Next_Page = NULL;
	Title_Page[0][7].Text.setCharacterSize(48);
	Title_Page[0][7].Text.setString("-where, there are gangsters");
	Title_Page[0][7].Text.setPosition(0, Title_Page[0][6].Text.getPosition().y + Title_Page[0][6].Text.getCharacterSize());
	
	Title_Page[0][8].new_game = false;
	Title_Page[0][8].Next_Page = NULL;
	Title_Page[0][8].Text.setCharacterSize(48);
	Title_Page[0][8].Text.setString("hunting you.....");
	Title_Page[0][8].Text.setPosition(0, Title_Page[0][7].Text.getPosition().y + Title_Page[0][7].Text.getCharacterSize());

	Title_Page[0][9].new_game = false;
	Title_Page[0][9].Next_Page = &Key_Bindings_Page;
	Title_Page[0][9].Text.setCharacterSize(48);
	Title_Page[0][9].Text.setString("");
	Title_Page[0][9].Text.setPosition(0, Title_Page[0][8].Text.getPosition().y + Title_Page[0][8].Text.getCharacterSize());
	
	Title_Page[0][10].new_game = false;
	Title_Page[0][10].Next_Page = &Key_Bindings_Page;
	Title_Page[0][10].Text.setCharacterSize(48);
	Title_Page[0][10].Text.setString("New Game");
	Title_Page[0][10].Text.setPosition(0, Title_Page[0][9].Text.getPosition().y + Title_Page[0][9].Text.getCharacterSize());
	
	Title_Page[0][11].new_game = false;
	Title_Page[0][11].Next_Page = &High_Scores_Page;
	Title_Page[0][11].Text.setCharacterSize(48);
	Title_Page[0][11].Text.setString("High Scores");
	Title_Page[0][11].Text.setPosition(0, Title_Page[0][10].Text.getPosition().y + Title_Page[0][10].Text.getCharacterSize());


	Key_Bindings_Page.resize(1);
	Key_Bindings_Page[0].resize(7);
	
	Key_Bindings_Page[0][0].new_game = false;
	Key_Bindings_Page[0][0].Next_Page = NULL;
	Key_Bindings_Page[0][0].Text.setCharacterSize(72);
	Key_Bindings_Page[0][0].Text.setString("KEY BINDINGS");
	Key_Bindings_Page[0][0].Text.setPosition(0,0);
	
	Key_Bindings_Page[0][1].new_game = false;
	Key_Bindings_Page[0][1].Next_Page = NULL;
	Key_Bindings_Page[0][1].Text.setCharacterSize(36);
	Key_Bindings_Page[0][1].Text.setString("Left Mouse Button: fire weapon");
	Key_Bindings_Page[0][1].Text.setPosition(0, Key_Bindings_Page[0][0].Text.getPosition().y + Key_Bindings_Page[0][0].Text.getCharacterSize());
	
	Key_Bindings_Page[0][2].new_game = false;
	Key_Bindings_Page[0][2].Next_Page = NULL;
	Key_Bindings_Page[0][2].Text.setCharacterSize(36);
	Key_Bindings_Page[0][2].Text.setString("W/A/S/D: movement");
	Key_Bindings_Page[0][2].Text.setPosition(0, Key_Bindings_Page[0][1].Text.getPosition().y + Key_Bindings_Page[0][1].Text.getCharacterSize());
	
	Key_Bindings_Page[0][3].new_game = false;
	Key_Bindings_Page[0][3].Next_Page = NULL;
	Key_Bindings_Page[0][3].Text.setCharacterSize(36);
	Key_Bindings_Page[0][3].Text.setString("Q: stop bleeding out");
	Key_Bindings_Page[0][3].Text.setPosition(0, Key_Bindings_Page[0][2].Text.getPosition().y + Key_Bindings_Page[0][2].Text.getCharacterSize());
	
	Key_Bindings_Page[0][4].new_game = false;
	Key_Bindings_Page[0][4].Next_Page = NULL;
	Key_Bindings_Page[0][4].Text.setCharacterSize(36);
	Key_Bindings_Page[0][4].Text.setString("E: reload weapon");
	Key_Bindings_Page[0][4].Text.setPosition(0, Key_Bindings_Page[0][3].Text.getPosition().y + Key_Bindings_Page[0][3].Text.getCharacterSize());

	Key_Bindings_Page[0][5].new_game = false;
	Key_Bindings_Page[0][5].Next_Page = &Tips_And_Advice_Page;
	Key_Bindings_Page[0][5].Text.setCharacterSize(36);
	Key_Bindings_Page[0][5].Text.setString("(click here to continue)");
	Key_Bindings_Page[0][5].Text.setPosition(0, Key_Bindings_Page[0][4].Text.getPosition().y + Key_Bindings_Page[0][4].Text.getCharacterSize());

	Tips_And_Advice_Page.resize(1);
	Tips_And_Advice_Page[0].resize(12);
	
	Tips_And_Advice_Page[0][0].new_game = false;
	Tips_And_Advice_Page[0][0].Next_Page = NULL;
	Tips_And_Advice_Page[0][0].Text.setCharacterSize(72);
	Tips_And_Advice_Page[0][0].Text.setString("ADVICE");
	Tips_And_Advice_Page[0][0].Text.setPosition(0,0);

	Tips_And_Advice_Page[0][1].new_game = false;
	Tips_And_Advice_Page[0][1].Next_Page = NULL;
	Tips_And_Advice_Page[0][1].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][1].Text.setString(".)Calm civilian's go about their business");
	Tips_And_Advice_Page[0][1].Text.setPosition(0, Tips_And_Advice_Page[0][0].Text.getPosition().y + Tips_And_Advice_Page[0][0].Text.getCharacterSize());

	Tips_And_Advice_Page[0][2].new_game = false;
	Tips_And_Advice_Page[0][2].Next_Page = NULL;
	Tips_And_Advice_Page[0][2].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][2].Text.setString(".)Gunshots aggravate civilians and hostiles for a short amount of time");
	Tips_And_Advice_Page[0][2].Text.setPosition(0, Tips_And_Advice_Page[0][1].Text.getPosition().y + Tips_And_Advice_Page[0][1].Text.getCharacterSize());

	Tips_And_Advice_Page[0][3].new_game = false;
	Tips_And_Advice_Page[0][3].Next_Page = NULL;
	Tips_And_Advice_Page[0][3].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][3].Text.setString(".)Civilians are invincible");
	Tips_And_Advice_Page[0][3].Text.setPosition(0, Tips_And_Advice_Page[0][2].Text.getPosition().y + Tips_And_Advice_Page[0][2].Text.getCharacterSize());

	Tips_And_Advice_Page[0][4].new_game = false;
	Tips_And_Advice_Page[0][4].Next_Page = NULL;
	Tips_And_Advice_Page[0][4].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][4].Text.setString(".)Calm hostile's wander randomly");
	Tips_And_Advice_Page[0][4].Text.setPosition(0, Tips_And_Advice_Page[0][3].Text.getPosition().y + Tips_And_Advice_Page[0][3].Text.getCharacterSize());

	Tips_And_Advice_Page[0][5].new_game = false;
	Tips_And_Advice_Page[0][5].Next_Page = NULL;
	Tips_And_Advice_Page[0][5].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][5].Text.setString(".)Hostile's will shoot player on sight immediately");
	Tips_And_Advice_Page[0][5].Text.setPosition(0, Tips_And_Advice_Page[0][4].Text.getPosition().y + Tips_And_Advice_Page[0][4].Text.getCharacterSize());

	Tips_And_Advice_Page[0][6].new_game = false;
	Tips_And_Advice_Page[0][6].Next_Page = NULL;
	Tips_And_Advice_Page[0][6].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][6].Text.setString(".)W/o line of sight, aggravated hostile's will move towards player (faster if blood trail is visible)");
	Tips_And_Advice_Page[0][6].Text.setPosition(0, Tips_And_Advice_Page[0][5].Text.getPosition().y + Tips_And_Advice_Page[0][5].Text.getCharacterSize());

	Tips_And_Advice_Page[0][7].new_game = false;
	Tips_And_Advice_Page[0][7].Next_Page = NULL;
	Tips_And_Advice_Page[0][7].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][7].Text.setString(".)Hostile NPC's wear blue suits with gray pin stripes");
	Tips_And_Advice_Page[0][7].Text.setPosition(0, Tips_And_Advice_Page[0][6].Text.getPosition().y + Tips_And_Advice_Page[0][6].Text.getCharacterSize());

	Tips_And_Advice_Page[0][8].new_game = false;
	Tips_And_Advice_Page[0][8].Next_Page = NULL;
	Tips_And_Advice_Page[0][8].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][8].Text.setString(".)You have infinite ammunition and medical supplies");
	Tips_And_Advice_Page[0][8].Text.setPosition(0, Tips_And_Advice_Page[0][7].Text.getPosition().y + Tips_And_Advice_Page[0][7].Text.getCharacterSize());

	Tips_And_Advice_Page[0][9].new_game = false;
	Tips_And_Advice_Page[0][9].Next_Page = NULL;
	Tips_And_Advice_Page[0][9].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][9].Text.setString(".) Health regenerates over time, unless you see blood droplets falling as you walk,");
	Tips_And_Advice_Page[0][9].Text.setPosition(0, Tips_And_Advice_Page[0][8].Text.getPosition().y + Tips_And_Advice_Page[0][8].Text.getCharacterSize());

	Tips_And_Advice_Page[0][10].new_game = false;
	Tips_And_Advice_Page[0][10].Next_Page = NULL;
	Tips_And_Advice_Page[0][10].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][10].Text.setString(" in which case you need to stitch yourself up");
	Tips_And_Advice_Page[0][10].Text.setPosition(0, Tips_And_Advice_Page[0][9].Text.getPosition().y + Tips_And_Advice_Page[0][9].Text.getCharacterSize());

	Tips_And_Advice_Page[0][11].new_game = true;
	Tips_And_Advice_Page[0][11].Next_Page = NULL;
	Tips_And_Advice_Page[0][11].Text.setCharacterSize(24);
	Tips_And_Advice_Page[0][11].Text.setString("(click here to continue)");
	Tips_And_Advice_Page[0][11].Text.setPosition(0, Tips_And_Advice_Page[0][10].Text.getPosition().y + Tips_And_Advice_Page[0][10].Text.getCharacterSize());

	High_Scores_Page.resize(2);
	High_Scores_Page[0].resize(13);
	High_Scores_Page[1].resize(11);

	High_Scores_Page[0][0].new_game = false;
	High_Scores_Page[0][0].Next_Page = NULL;
	High_Scores_Page[0][0].Text.setCharacterSize(72);
	High_Scores_Page[0][0].Text.setString("TOP TEN");
	High_Scores_Page[0][0].Text.setPosition(0, 0);

	High_Scores_Page[0][1].new_game = false;
	High_Scores_Page[0][1].Next_Page = &Title_Page;
	High_Scores_Page[0][1].Text.setCharacterSize(36);
	High_Scores_Page[0][1].Text.setString("(main menu)");
	High_Scores_Page[0][1].Text.setPosition(0, High_Scores_Page[0][0].Text.getPosition().y + High_Scores_Page[0][0].Text.getCharacterSize());

	High_Scores_Page[0][2].new_game = false;
	High_Scores_Page[0][2].Next_Page = NULL;
	High_Scores_Page[0][2].Text.setCharacterSize(36);
	High_Scores_Page[0][2].Text.setString("Time Alive");
	High_Scores_Page[0][2].Text.setPosition(0, High_Scores_Page[0][1].Text.getPosition().y + High_Scores_Page[0][1].Text.getCharacterSize());

	High_Scores_Page[1][0].new_game = false;
	High_Scores_Page[1][0].Next_Page = NULL;
	High_Scores_Page[1][0].Text.setCharacterSize(36);
	High_Scores_Page[1][0].Text.setString("Enemies Killed");
	High_Scores_Page[1][0].Text.setFont(*Font);
	High_Scores_Page[1][0].Text.setPosition(1600 - High_Scores_Page[1][0].Text.getGlobalBounds().width, High_Scores_Page[0][2].Text.getPosition().y);

	for(unsigned int i = 3; i < High_Scores_Page[0].size(); i++)
	{
		High_Scores_Page[0][i].Text.setCharacterSize(36);
		High_Scores_Page[0][i].Text.setString("");
		High_Scores_Page[0][i].Text.setPosition(High_Scores_Page[0][i - 1].Text.getPosition().x, High_Scores_Page[0][i - 1].Text.getPosition().y + High_Scores_Page[0][i - 1].Text.getCharacterSize());
	}

	for(unsigned int i = 1; i < High_Scores_Page[1].size(); i++)
	{
		High_Scores_Page[1][i].Text.setCharacterSize(36);
		High_Scores_Page[1][i].Text.setString("");
		High_Scores_Page[1][i].Text.setPosition(High_Scores_Page[1][i - 1].Text.getPosition().x, High_Scores_Page[1][i - 1].Text.getPosition().y + High_Scores_Page[1][i - 1].Text.getCharacterSize());
	}

	for(unsigned int i = 0; i < Title_Page.size(); i++)
	{
		for(unsigned int j = 0; j < Title_Page[i].size(); j++)
		{
			Title_Page[i][j].Text.setFont(*Font);
			Title_Page[i][j].Text.setColor(sf::Color::Black);
			Title_Page[i][j].Text.setStyle(sf::Text::Bold);
		}
	}

	for(unsigned int i = 0; i < Difficulty_Page.size(); i++)
	{
		for(unsigned int j = 0; j < Difficulty_Page[i].size(); j++)
		{
			Difficulty_Page[i][j].Text.setFont(*Font);
			Difficulty_Page[i][j].Text.setColor(sf::Color::Black);
			Difficulty_Page[i][j].Text.setStyle(sf::Text::Bold);
		}
	}

	for(unsigned int i = 0; i < Tips_And_Advice_Page.size(); i++)
	{
		for(unsigned int j = 0; j < Tips_And_Advice_Page[i].size(); j++)
		{
			Tips_And_Advice_Page[i][j].Text.setFont(*Font);
			Tips_And_Advice_Page[i][j].Text.setColor(sf::Color::Black);
			Tips_And_Advice_Page[i][j].Text.setStyle(sf::Text::Bold);
		}
	}

	for(unsigned int i = 0; i < Key_Bindings_Page.size(); i++)
	{
		for(unsigned int j = 0; j < Key_Bindings_Page[i].size(); j++)
		{
			Key_Bindings_Page[i][j].Text.setFont(*Font);
			Key_Bindings_Page[i][j].Text.setColor(sf::Color::Black);
			Key_Bindings_Page[i][j].Text.setStyle(sf::Text::Bold);
		}
	}

	for(unsigned int i = 0; i < High_Scores_Page.size(); i++)
	{
		for(unsigned int j = 0; j < High_Scores_Page[i].size(); j++)
		{
			High_Scores_Page[i][j].Text.setFont(*Font);
			High_Scores_Page[i][j].Text.setColor(sf::Color::Black);
			High_Scores_Page[i][j].Text.setStyle(sf::Text::Bold);
		}
	}

	updateHighScores();
}

void PreGameMenu::playMusic()
{
	if(Main_Menu_Music.getStatus() != sf::Sound::Playing)
	{
		Main_Menu_Music.play();
	}
}

void PreGameMenu::updateHighScores()
{
	std::ifstream High_Scores("high_scores.txt");
	std::string string;

	std::vector<std::string> Times_Vector;
	std::vector<std::string> Kills_Vector;

	unsigned int iterator = 0;
	
	while (std::getline(High_Scores, string))
    {
		if(iterator == 0)
		{
			Times_Vector.push_back(string);
		}
		
		if(iterator == 1)
		{
			Kills_Vector.push_back(string);
		}

		iterator++;
	  
		if(iterator == 2)
		{
			iterator = 0;
		}
    }

	std::vector<int> Temp_Times;
	Temp_Times.resize(Times_Vector.size());
	std::vector<int> Temp_Kills;
	Temp_Kills.resize(Kills_Vector.size());

	for(unsigned int i = 0; i < Times_Vector.size(); i++)
	{
		std::stringstream temp(Times_Vector[i]);
		temp >> Temp_Times[i];
	}

	for(unsigned int i = 0; i < Kills_Vector.size(); i++)
	{
		std::stringstream temp(Kills_Vector[i]);
		temp >> Temp_Kills[i];
	}

	std::sort(Temp_Times.begin(), Temp_Times.end(), std::greater<int>());
	std::sort(Temp_Kills.begin(), Temp_Kills.end(), std::greater<int>());

	for(unsigned int i = 0; i < Temp_Times.size(); i++)
	{
		std::stringstream temp;
		temp << Temp_Times[i];
		Times_Vector[i] = temp.str();
	}
	for(unsigned int i = 0; i < Temp_Kills.size(); i++)
	{
		std::stringstream temp;
		temp << Temp_Kills[i];
		Kills_Vector[i] = temp.str();
	}

	while(Times_Vector.size() > 10)
	{
		Times_Vector.pop_back();
	}

	while(Kills_Vector.size() > 10)
	{
		Kills_Vector.pop_back();
	}

	for(unsigned int i = 0; i <10; i++)
	{
		if(i < Times_Vector.size())
		{
			High_Scores_Page[0][i+3].Text.setString(Times_Vector[i]);
		}
		else
		{
			High_Scores_Page[0][i+3].Text.setString("");
		}
	}

	for(unsigned int i = 0; i < 10; i++)
	{
		if(i < Kills_Vector.size())
		{
			High_Scores_Page[1][i+1].Text.setString(Kills_Vector[i]);
		}
		else
		{
			High_Scores_Page[1][i+1].Text.setString("");
		}
	}

	High_Scores.close();
}

void PreGameMenu::drawEverything(sf::RenderWindow &Window)
{
	Window.clear();

	Window.draw(Background);

	for(unsigned int i = 0; i < Current_Page->size(); i++)
	{
		for(unsigned int j = 0; j < Current_Page->at(i).size(); j++)
		{
			Window.draw(Current_Page->at(i)[j].Text);
		}
	}
}
