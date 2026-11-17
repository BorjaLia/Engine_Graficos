#pragma once

#include "Window.h"

namespace engine
{
	class Time
	{
	protected:

		friend class Window;

		static void UpdateTime(double time);

	public:

		Time();
		~Time();

		static double GetTime() { return currentTime; }
		static double GetDeltaTime() { return currentTime; }

	private:

		static double currentTime;
		static double lastUpdateTime;
	};
}