/*
* "PreGameMenu" will be the first user interface of the program. The user can
* view their high scores, or begin a new game; beginning a new game will force
* the user through a few pages of text, explaing the game. At the end of the
* last page, the game will begin, and the present instance of "PreGameMenu"
* will be deleted from main.cpp.
* To be instantiated in main.cpp.
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include <fstream>
#include <algorithm>
#include <sstream>

class PreGameMenu
{
private: sf::Font *Font;

private: sf::Texture *Background_Texture;

private: sf::RectangleShape Background;

public: sf::RectangleShape getBackground(){return Background;}

private: sf::SoundBuffer Main_Menu_Music_Buffer;

private: sf::Sound Main_Menu_Music;

public: void playMusic();

/*A line of text which can be clicked on to go to another page of the pre-game
menu, start the main portion of the game, or nothing at all. A 2D vector of
instances creates a page of text the user will interact with.*/
private: struct ClickableText
{
 sf::Text Text;
 std::vector<std::vector<ClickableText> > *Next_Page;
 bool new_game;
};

private: std::vector<std::vector<ClickableText> > *Current_Page;

private: std::vector<std::vector<ClickableText> > Title_Page;

private: std::vector<std::vector<ClickableText> > High_Scores_Page;

private: std::vector<std::vector<ClickableText> > Key_Bindings_Page;

private: std::vector<std::vector<ClickableText> > Tips_And_Advice_Page;

private: std::vector<std::vector<ClickableText> > Difficulty_Page;

/*Reads text from "hiscores.txt", converts them to integers, sorts them,
and updates the last ten elements of "High_Scores_Page"*/
private: void updateHighScores();

/*Other than closing the program, only handles the clicking of text, whether
the user wants to see a different page or start the game.*/
public: void eventHandling(sf::RenderWindow&,
			Game*&
			);



public: PreGameMenu();

public: void drawEverything(sf::RenderWindow&
			);


};