#include "GameTime.h"

double engine::Time::currentTime = 0;
double engine::Time::lastUpdateTime = 0;

void engine::Time::UpdateTime(double time)
{
	lastUpdateTime = currentTime;
	currentTime = time;
}

engine::Time::Time()
{
}

engine::Time::~Time()
{
}
