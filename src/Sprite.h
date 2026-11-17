#ifndef SPRITE_H
#define SPRITE_H

#include "Entity2D.h"
#include "Animation.h"
#include "Texture.h"
#include <limits>

namespace engine
{
	class Sprite : public Entity2D
	{
	public:
		DllExport Sprite();
		DllExport ~Sprite(void);

		DllExport void SetTextureCoordinates(float u0, float v0,
			float u1, float v1,
			float u2, float v2,
			float u3, float v3);

		DllExport void SetTexture(const Texture& texture);
		DllExport void SetAnimation(Animation* animation);

		DllExport void Start() override;
		DllExport void Update() override;
		//DllExport void Draw(Renderer& rkRenderer);

	private:

		Texture texture;
		math::Vertex texturedVertex[4];
		Animation* animation;
		int currentFrame;
		int previousFrame;

	};
}
#endif