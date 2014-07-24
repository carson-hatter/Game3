#include "PauseableSFClock.h"

PauseableSFClock::PauseableSFClock()
{
	paused = true;
}

void PauseableSFClock::restart()
{
	Clock.restart();
	Place_Holder_Time = sf::seconds(0);
}

void PauseableSFClock::pause()
{
	if(!paused)
	{
		Place_Holder_Time = Clock.getElapsedTime();
		paused = true;
	}
}

void PauseableSFClock::resume()
{
	if(paused)
	{
		Clock.restart();
		paused = false;
	}
}

sf::Time PauseableSFClock::getElapsedTime()
{
	if(!paused)
	{
		return (Place_Holder_Time + Clock.getElapsedTime());
	}
	else
	{
		return Place_Holder_Time;
	}
}
