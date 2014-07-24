/*
* A standard SFML Clock, except it can pause.
*/
#pragma once

#include <SFML/Graphics.hpp>

class PauseableSFClock
{
private: sf::Clock Clock;

private: sf::Time Place_Holder_Time;

public: PauseableSFClock();

public: void pause();

public: void resume();

public: void restart();

public: sf::Time getElapsedTime();

private: bool paused;
};