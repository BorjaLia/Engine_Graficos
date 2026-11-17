#ifndef FRAME_H
#define FRAME_H

namespace engine
{
	struct UVCoords
	{
		float u, v;
	};

	class Frame
	{
	public:
		Frame();
		~Frame();
		UVCoords uvCoords[4];
	};
}
#endif