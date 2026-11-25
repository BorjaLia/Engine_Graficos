#ifndef SPRITE_H
#define SPRITE_H

#include "Entity2D.h"
#include "Animation.h"
#include "Texture.h"
#include "UVCoords.h"
#include <limits>

namespace engine
{
	class Sprite : public Entity2D
	{
	protected:

		Animation* animation;

		int currentFrame;	
		int previousFrame;

		DllExport void SetAnimation(Animation* animation);
	
	public:
		DllExport Sprite();
		DllExport ~Sprite(void);

		DllExport void SetTextureCoordinates(float u0, float v0,
			float u1, float v1,
			float u2, float v2,
			float u3, float v3);

		DllExport void SetTextureCoordinates(math::UVCoords uv1, math::UVCoords uv2, math::UVCoords uv3, math::UVCoords uv4);

		DllExport void SetTexture(Texture& texture);
		DllExport Texture GetTexture() { return *texture; };

		DllExport void FlipX() { isFlippedX = !isFlippedX; }
		DllExport void FlipY() { isFlippedY = !isFlippedY; }

		DllExport void SetFlipX(bool flipped) { isFlippedX = flipped; }
		DllExport void SetFlipY(bool flipped) { isFlippedY = flipped; }
		
		DllExport bool GetFlipX() { return isFlippedX; }
		DllExport bool GetFlipY() { return isFlippedY; }

		DllExport void Start() override;
		DllExport void Update() override;

	private:
		Texture* texture;

		bool isFlippedX = false;
		bool isFlippedY = false;
	};
}
#endif