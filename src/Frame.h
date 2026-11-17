#ifndef FRAME_H
#define FRAME_H

#include "UVCoords.h"

namespace engine
{
	class Frame
	{
	public:
		Frame();
		~Frame();
		math::UVCoords uvCoords[4];
	};
}
#endif