#include "Game.h"

sf::Vector2i Game::convertSFMLToMapIndex(sf::Vector2f Position)
{
	sf::Vector2i u_i_to_return;

	u_i_to_return = sf::Vector2i(0,0);

	u_i_to_return.y = (floor(Position.y / Map[0][0].getBoundary().height));
	u_i_to_return.x = (floor(Position.x / Map[0][0].getBoundary().width));

	return u_i_to_return;
}

void Game::determinePassiveNPCsRotations()
{
	P_C.Current_Grid->determinePassiveNPCsRotations();

	if(P_C.Current_Grid->North_Grid)
	{
		P_C.Current_Grid->North_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->Northeast_Grid)
	{
		P_C.Current_Grid->Northeast_Grid->determinePassiveNPCsRotations();
	}
	
	if(P_C.Current_Grid->Northwest_Grid)
	{
		P_C.Current_Grid->Northwest_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->South_Grid)
	{
		P_C.Current_Grid->South_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->Southeast_Grid)
	{
		P_C.Current_Grid->Southeast_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->Southwest_Grid)
	{
		P_C.Current_Grid->Southwest_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->East_Grid)
	{
		P_C.Current_Grid->East_Grid->determinePassiveNPCsRotations();
	}

	if(P_C.Current_Grid->West_Grid)
	{
		P_C.Current_Grid->West_Grid->determinePassiveNPCsRotations();
	}	
}

Game::Game(sf::RenderWindow &Window)
{
	Dry_Fire_Buffer.loadFromFile("dry_fire_sound.wav");
	Gun_Shot_Buffer.loadFromFile("gun_shot_sound.wav");
	Reloading_Buffer.loadFromFile("reloading_sound.wav");
	Stitching_Buffer.loadFromFile("stitching_sound.flac");
	Stitching.setBuffer(Stitching_Buffer);
	Reloading.setBuffer(Reloading_Buffer);
	Gun_Shot.setBuffer(Gun_Shot_Buffer);
	Dry_Fire.setBuffer(Dry_Fire_Buffer);

	hostiles_killed = 0;

	sf::Font Font;
	Font.loadFromFile("cour.ttf");
	sf::Text Text;
	Text.setPosition(0,0);
	Text.setCharacterSize(24);
	Text.setColor(sf::Color::White);
	Text.setFont(Font);

	Text.setString("Loading Textures");
	Window.clear(sf::Color::Black);
	Window.draw(Text);
	Window.display();

	minimum_number_of_hostile_npcs = 3;

	Character_Sprite_Sheet.loadFromFile("characterspritesheet.jpg");
	Tall_Collisions_Sprite_Sheet.loadFromFile("tall_collisions_sprite_sheet.jpg");
	Short_Collisions_Sprite_Sheet.loadFromFile("short_collisions_sprite_sheet.jpg");
	Floor_Tiles_Sprite_Sheet.loadFromFile("floor_tiles_sprite_sheet.jpg");
	
	unsigned int map_columns = 5;
	unsigned int map_rows = 5;

	const sf::Vector2i Grid_Dim(1500,1500);

	Text.setString("Constructing City Blocks");
	Window.clear(sf::Color::Black);
	Window.draw(Text);
	Window.display();

	Map.resize(map_columns);
	for(unsigned int i = 0; i < Map.size(); i++)
	{
		for(unsigned int j = 0; j < map_rows; j++)
		{
			Map[i].push_back(Grid(Tall_Collisions_Sprite_Sheet, Short_Collisions_Sprite_Sheet, Floor_Tiles_Sprite_Sheet, Character_Sprite_Sheet, sf::FloatRect(Grid_Dim.x * j, Grid_Dim.y * i, Grid_Dim.x, Grid_Dim.y)));
		}
	}

	for(unsigned int i = 0; i < Map.size(); i++)
	{
		for(unsigned int j = 0; j < Map[i].size(); j++)
		{
			if(i > 0)
			{
				Map[i][j].North_Grid = &Map[i - 1][j];
			}
			else
			{
				Map[i][j].North_Grid = NULL;
			}
			
			if((i > 0) && (j < Map[i].size() - 1))
			{
				Map[i][j].Northeast_Grid = &Map[i - 1][j + 1];
			}
			else
			{
				Map[i][j].Northeast_Grid = NULL;
			}
			
			if(j < Map[i].size() - 1)
			{
				Map[i][j].East_Grid = &Map[i][j + 1];
			}
			else
			{
				Map[i][j].East_Grid = NULL;
			}
			
			if((j < Map[i].size() - 1) && (i < Map.size() - 1))
			{
				Map[i][j].Southeast_Grid = &Map[i + 1][j + 1];
			}
			else
			{
				Map[i][j].Southeast_Grid = NULL;
			}
			
			if(i < Map.size() - 1)
			{
				Map[i][j].South_Grid = &Map[i + 1][j];
			}
			else
			{
				Map[i][j].South_Grid = NULL;
			}
			
			if((i < Map.size() - 1) && (j > 0))
			{
				Map[i][j].Southwest_Grid = &Map[i + 1][j - 1];
			}
			else
			{
				Map[i][j].Southwest_Grid = NULL;
			}
			
			if(j > 0)
			{
				Map[i][j].West_Grid = &Map[i][j - 1];
			}
			else
			{
				Map[i][j].West_Grid = NULL;
			}
			
			if((j > 0) && (i > 0))
			{
				Map[i][j].Northwest_Grid = &Map[i - 1][j - 1];
			}			
			else
			{
				Map[i][j].Northwest_Grid = NULL;
			}
		}
	}

	Text.setString("Building Adjacency Lists...");
	Window.clear(sf::Color::Black);
	Window.draw(Text);
	Window.display();

	for(unsigned int i = 0; i < Map.size(); i++)
	{
		for(unsigned int j = 0; j < Map[i].size(); j++)
		{
			Map[i][j].buildAdjList();
			Map[i][j].setPassiveNPCsAdjLists();

			sf::String Temp;
			Temp = Text.getString();
			Temp += ".";
			Text.setString(Temp);
			Window.clear(sf::Color::Black);
			Window.draw(Text);
			Window.display();
		}
	}
	sf::Vector2f P_C_Initial_Position(1000,200);
	P_C = PC(
		sf::IntRect(250,0,25,100), 
		&Character_Sprite_Sheet, 
		P_C_Initial_Position, 
		Map[convertSFMLToMapIndex(P_C_Initial_Position).y][convertSFMLToMapIndex(P_C_Initial_Position).x],
		sf::Vector2i(Grid_Dim.x * Map[0].size(), Grid_Dim.y * Map.size())
	);

	Text.setString("Constructing Playable Character");
	Window.clear(sf::Color::Black);
	Window.draw(Text);
	Window.display();

	P_C_Centered_View.setSize(1600,900);
	P_C_Centered_View.setCenter(P_C.getBodySprite().getPosition());
	P_C_Centered_View.zoom(1.2);

	map_width = (Grid_Dim.x * map_rows);

	hostile_npcs_vector_iterator = 0;

	for(unsigned int i = 0; i < Map.size(); i++)
	{
		for(unsigned int j = 0; j < Map[i].size(); j++)
		{
			Map[i][j].restartAllCivPocketWatches();
		}
	}
}

void Game::eraseExpiredBloodSplatters()
{
	for(unsigned int i = 0; i < Blood_Splatters.size(); i++)
	{
		if(Blood_Splatters[i].isExpired())
		{
			Blood_Splatters.erase(Blood_Splatters.begin() + i);
		}
	}
}

void Game::regenPCHealth(sf::Time Frame_Time)
{
	float health_to_regen = 1;

	if(!P_C.is_bleeding)
	{
		if(P_C.health < P_C.getMaxHealth())
		{
			P_C.health += Frame_Time.asSeconds() * health_to_regen;

			if(P_C.health >= P_C.getMaxHealth())
			{
				P_C.health = P_C.getMaxHealth();
			}
		}
	}
}

void Game::pcRotation(sf::Vector2f Mouse_Position)
{
	P_C.characterRotation(Mouse_Position);
}

void Game::buildDeathSprites()
{
	for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
	{
		if(Hostile_NPCs[i]->isDead())
		{
			if(!Hostile_NPCs[i]->death_sprite_constructed)
			{
				hostiles_killed++;
				Hostile_NPCs[i]->constructDeathSprite();
			}
		}
	}
}

void Game::drawEverything(sf::RenderWindow &Window)
{
	Window.clear();

	P_C_Centered_View.setCenter(P_C.getBodySprite().getPosition());
	
	Window.setView(P_C_Centered_View);
	
	if(P_C.Current_Grid)
	{
		P_C.Current_Grid->drawEverything(Window);

		if(P_C.Current_Grid->North_Grid)
		{
			P_C.Current_Grid->North_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->Northeast_Grid)
		{
			P_C.Current_Grid->Northeast_Grid->drawEverything(Window);
		}
		
		if(P_C.Current_Grid->Northwest_Grid)
		{
			P_C.Current_Grid->Northwest_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->South_Grid)
		{
			P_C.Current_Grid->South_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->Southeast_Grid)
		{
			P_C.Current_Grid->Southeast_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->Southwest_Grid)
		{
			P_C.Current_Grid->Southwest_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->East_Grid)
		{
			P_C.Current_Grid->East_Grid->drawEverything(Window);
		}

		if(P_C.Current_Grid->West_Grid)
		{
			P_C.Current_Grid->West_Grid->drawEverything(Window);
		}

		for(unsigned int i = 0; i < Blood_Trail.getBloodDropVectorSize(); i++)
		{
			Window.draw(Blood_Trail.getBloodDropSprite(i));
		}

		for(unsigned int i = 0; i < Blood_Splatters.size(); i++)
		{
			Window.draw(Blood_Splatters[i].getCircleSprite());
			Window.draw(Blood_Splatters[i].getTriangleSprite());
			for(unsigned int j = 0; j < Blood_Splatters[i].getMistSpritesVectorSize(); j++)
			{
				Window.draw(Blood_Splatters[i].getMistSprite(j));
			}
		}

		for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
		{
			if(!Hostile_NPCs[i]->isDead())
			{
				Window.draw(Hostile_NPCs[i]->getLeftFootSprite());
				Window.draw(Hostile_NPCs[i]->getRightFootSprite());
				Window.draw(Hostile_NPCs[i]->getRightArmSprite());
				Window.draw(Hostile_NPCs[i]->getBodySprite());
				Window.draw(Hostile_NPCs[i]->getHeadSprite());
			}
			else
			{
				Window.draw(Hostile_NPCs[i]->getDeathSpriteHead());
				for(unsigned int j = 0; j < Hostile_NPCs[i]->getDeathSpriteVectorSize(); j++)
				{
					Window.draw(Hostile_NPCs[i]->getDeathSpritePiece(j));
				}
			}
		}

		Window.draw(P_C.getLeftFootSprite());
		Window.draw(P_C.getRightFootSprite());
		Window.draw(P_C.getRightArmSprite());
		Window.draw(P_C.getBodySprite());
		Window.draw(P_C.getHeadSprite());
	}

	Window.setView(Window.getDefaultView());

	Window.draw(H_U_D.getHealthSprite());
	Window.draw(H_U_D.getGunSprite());
	Window.draw(H_U_D.getStitchingProgressBar());
	Window.draw(H_U_D.getReloadingProgressBar());

	Window.setView(P_C_Centered_View);
}

unsigned int Game::countLivingHostileNPCs()
{
	unsigned int living_hostile_npc_count = 0;

	for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
	{
		if(Hostile_NPCs[i]->health > 0)
		{
			living_hostile_npc_count++;
		}
	}

	return living_hostile_npc_count;
}

void Game::spawnHostileNPCs()
{
	while(countLivingHostileNPCs() < minimum_number_of_hostile_npcs)
	{
		 sf::Vector2i PC_Position;
		 PC_Position.x = convertSFMLToMapIndex(P_C.getBodySprite().getPosition()).x;
		 PC_Position.y = convertSFMLToMapIndex(P_C.getBodySprite().getPosition()).y;
		 std::vector<sf::Vector2i> Valid_Map_Indexes;
		for(unsigned int i = 0; i < Map.size(); i++)
		{
			for(unsigned int j = 0; j < Map[i].size(); j++)
			{
				if((i != PC_Position.y) || (j != PC_Position.x))
				{
					Valid_Map_Indexes.push_back(sf::Vector2i(j, i));
				}
			}
		}

		unsigned int random_number = rand() % Valid_Map_Indexes.size();

		sf::Vector2f Initial_Position = Map[Valid_Map_Indexes[random_number].y][Valid_Map_Indexes[random_number].x].getHostileNPCSpawnVector().getVector();
		Hostile_NPCs.push_back(new NPCAssassin(sf::IntRect(0,0,25,100), &Character_Sprite_Sheet, Initial_Position, Map[Valid_Map_Indexes[random_number].y][Valid_Map_Indexes[random_number].x], Blood_Trail/*, Difficulty*/));
		Hostile_NPCs.back()->resumeAggroClock();
		Hostile_NPCs.back()->resumePocketWatch();
	}
}

void Game::processBloodTrail()
{
	if(P_C.is_bleeding)
	{
		Blood_Trail.addBloodDrops(P_C.getBodySprite().getPosition());
	}

	Blood_Trail.eraseExpiredBloodDrops();
}

void Game::playGridSFX()
{
	if(P_C.Current_Grid)
	{
		P_C.Current_Grid->playBackgroundSFX(P_C.getBodySprite().getPosition());
	}
}

void Game::moveCharacterSprites(sf::Time Frame_Time)
{
	P_C.movement(Frame_Time);
	P_C.switchCurrentGrid();
	P_C.updateCharacterSprite();
	P_C.setHeadRotation();

	for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
	{
		Hostile_NPCs[i]->movement(Frame_Time);
		Hostile_NPCs[i]->switchCurrentGrid();
		Hostile_NPCs[i]->updateCharacterSprite();
	}

	Grid *PCs_Current_Grid = P_C.Current_Grid;

	PCs_Current_Grid->moveCharacterSprites(Frame_Time);

	if(PCs_Current_Grid->North_Grid)
	{
		PCs_Current_Grid->North_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->Northeast_Grid)
	{
		PCs_Current_Grid->Northeast_Grid->moveCharacterSprites(Frame_Time);
	}
	
	if(PCs_Current_Grid->Northwest_Grid)
	{
		PCs_Current_Grid->Northwest_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->South_Grid)
	{
		PCs_Current_Grid->South_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->Southeast_Grid)
	{
		PCs_Current_Grid->Southeast_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->Southwest_Grid)
	{
		PCs_Current_Grid->Southwest_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->East_Grid)
	{
		PCs_Current_Grid->East_Grid->moveCharacterSprites(Frame_Time);
	}

	if(PCs_Current_Grid->West_Grid)
	{
		PCs_Current_Grid->West_Grid->moveCharacterSprites(Frame_Time);
	}
}

void Game::eventHandling(sf::RenderWindow &Window)
{
	sf::Event Event;
    while (Window.pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed)
		{
			Window.close();
		}

		if(Event.type == sf::Event::MouseButtonReleased)
		{
			if(Event.mouseButton.button == sf::Mouse::Left)
			{
				if((!P_C.isReloading()) && (P_C.canAttack()))
				{
					if(P_C.getBullets() > 0)
					{
						Gun_Shot.play();
						gunShot(P_C.Current_Grid);
						P_C.restartAttackClock();
						P_C.decrementBulletsInClip();

						for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
						{
							if(P_C.attack(Hostile_NPCs[i]->getBodySprite().getPosition(), Hostile_NPCs[i]->health))
							{
								Blood_Splatters.push_back(BloodSplatter(Hostile_NPCs[i]->getBodySprite().getPosition(), P_C.getBodySprite().getPosition()));
							}
						}
					}
					else
					{
						Dry_Fire.play();
					}
				}
			}
		}
		if(Event.type == sf::Event::KeyReleased)
		{
			if(Event.key.code == sf::Keyboard::Q)
			{
				
				if(P_C.stitching())
				{
					Stitching.play();
				}
			}
			if(Event.key.code == sf::Keyboard::E)
			{
				
				if(P_C.reloading())
				{
					Reloading.play();
				}
			}
		}
    }
}

bool Game::isGameOver()
{
	if(P_C.isDead())
	{
		std::ofstream High_Scores("high_scores.txt", std::ios::app);

		std::stringstream Seconds_Alive;
		std::stringstream Hostiles_Killed;

		Seconds_Alive << int(Seconds_Alive_Clock.getElapsedTime().asSeconds());
		Hostiles_Killed << int(hostiles_killed);

		High_Scores << Seconds_Alive.str();
		High_Scores << "\n";
		High_Scores << Hostiles_Killed.str();
		High_Scores << "\n";

		High_Scores.close();

		return true;
	}

	return false;
}

void Game::gunShot(Grid *Test_Grid)
{
	for(unsigned int i = 0; i < Hostile_NPCs.size(); i++)
	{
		Hostile_NPCs[i]->restartAggroClock();   
	}
	Test_Grid->restartAggroClocks();
}

void Game::incrementNPCIterators()
{
	hostile_npcs_vector_iterator++;

	if(hostile_npcs_vector_iterator == Hostile_NPCs.size())
	{
		hostile_npcs_vector_iterator = 0;
	}

	P_C.Current_Grid->incrementPassiveNPCIterators();
}

void Game::npcScripting()
{
	if(Hostile_NPCs.size() > 0)
	{
		if(Hostile_NPCs[hostile_npcs_vector_iterator]->chooseScript(P_C))
		{
			Gun_Shot.play();
			gunShot(Hostile_NPCs[hostile_npcs_vector_iterator]->getCurrentGrid());
			Blood_Splatters.push_back(BloodSplatter(P_C.getBodySprite().getPosition(), Hostile_NPCs[hostile_npcs_vector_iterator]->getBodySprite().getPosition()));
		}
	}

	P_C.Current_Grid->passiveNPCsScripting();
}

void Game::updateHUD()
{
	H_U_D.updateHUD(P_C.getHealthPercentage(), P_C.getAmmoPercentage(), P_C.getStitchingPercentage(), P_C.getReloadingPercentage());
}