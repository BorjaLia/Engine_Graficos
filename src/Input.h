#pragma once

/// The class that handles the Input
/// @ingroup Input


namespace engine
{
	class Input
	{
	public:
		Input();
		~Input();

		int Initialize();
		void Update();
		int Shutdown();

	private:

	};
}