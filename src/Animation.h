#ifndef ANIMATION_H
#define ANIMATION_H

#include "GameTime.h"
#include "Frame.h"
#include "Rect.h"
#include <vector>

#define DllExport __declspec( dllexport )

namespace engine
{
	/// The class responsible of holding the frames of an animation
	/// @ingroup Sprite
	
	class Animation
	{
	public:
		DllExport Animation(float length, std::string name = "NULL");
		DllExport ~Animation();

		DllExport void SetName(std::string newName);
		DllExport void SetLength(float lenght);

		DllExport void Update();

		DllExport void AddFrame(math::Rect rect, math::Vector2 textureSize);
		DllExport void AddFrames(math::Rect rect,math::Vector2 textureSize, int framesAmount);
		DllExport void AddFrames(math::Rect rect,math::Vector2 textureSize, math::Vector2 framesAmount);

		DllExport int CurrentFrame();

		DllExport std::vector<Frame>& GetFrames();

	private:

		std::string name;

		float currentFrame;

		float currentTime;

		float frameLength;
		float animLength;

		std::vector<Frame> frames;
	};
#endif
}