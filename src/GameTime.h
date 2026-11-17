#pragma once

#include "Core.h"
#include "Window.h"

namespace engine
{
	class ENGINE_API Time
	{
	protected:

		friend class Window;

		static void UpdateTime(double time);

	public:

		Time();
		~Time();

		static double GetTime() { return currentTime; }
		static double GetDeltaTime() { return currentTime - lastUpdateTime; }

	private:

		static double currentTime;
		static double lastUpdateTime;
	};
}