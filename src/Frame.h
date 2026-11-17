#ifndef FRAME_H
#define FRAME_H

#include "UVCoords.h"

namespace engine
{
	/// The class that holds the coordinates of a frame in a texture atlas
	/// @ingroup Sprite
	class Frame
	{
	public:
		Frame();
		~Frame();
		math::UVCoords uvCoords[4];
	};
}
#endif