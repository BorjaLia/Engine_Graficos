#ifndef ANIMATION_H
#define ANIMATION_H

#include "GameTime.h"
#include "Frame.h"
#include "Vector2.h"
#include <vector>

#define DllExport __declspec( dllexport )

namespace engine
{
	/// The class responsible of holding the frames of an animation
	/// @ingroup Sprite
	
	class Animation
	{
	public:
		DllExport Animation(std::string name = "NULL");
		DllExport ~Animation();

		DllExport void SetName(std::string newName);

		DllExport void Update();

		DllExport void AddFrame(float frameX, float frameY,
			float frameWidth, float frameHeigth,
			float textureWidth, float textureHeigth,
			float durationInSecs);

		DllExport void AddFrame(float frameX, float frameY,
			float frameWidth, float frameHeigth,
			float textureWidth, float textureHeigth,
			float durationInSecs,
			int frameCount);

		DllExport void AddFrame(math::Vector2 framePos,
			math::Vector2 frameSize,
			math::Vector2 textureSize,
			float durationInSecs);

		DllExport void AddFrame(math::Vector2 framePos,
			math::Vector2 frameSize,
			math::Vector2 textureSize,
			float durationInSecs,
			int frameCount);

		DllExport int CurrentFrame();

		DllExport std::vector<Frame>& GetFrames();

	private:

		std::string name;

		float currentFrame;

		float currentTime;

		float length;
		std::vector<Frame> frames;
	};
#endif
}