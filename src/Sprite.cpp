#include "Sprite.h"

engine::Sprite::Sprite(void) :
	texture(nullptr)
{
	texturedVertex[0].pos.x = -0.5;
	texturedVertex[0].pos.y = 0.5;
	//texturedVertex[0].pos.z = 0.0f;
	
	texturedVertex[1].pos.x = 0.5;
	texturedVertex[1].pos.y = 0.5;
	//texturedVertex[1].pos.z = 0.0f;
	
	texturedVertex[2].pos.x = -0.5;
	texturedVertex[2].pos.y = -0.5;
	//texturedVertex[2].pos.z = 0.0f;

	texturedVertex[3].pos.x = 0.5;
	texturedVertex[3].pos.y = -0.5;
	//texturedVertex[3].pos.z = 0.0f;
	
	texturedVertex[0].textureCoords.u = 0.0;
	texturedVertex[0].textureCoords.v = 0.0f;
	
	texturedVertex[1].textureCoords.u = 1.0;
	texturedVertex[1].textureCoords.v = 0.0;
	
	texturedVertex[2].textureCoords.u = 0.0;
	texturedVertex[2].textureCoords.v = 1.0;
	
	texturedVertex[3].textureCoords.u = 1.0;
	texturedVertex[3].textureCoords.v = 1.0;
}

engine::Sprite::~Sprite(void)
{
}

void engine::Sprite::SetTextureCoordinates(float u0, float v0,
	float u1, float v1,
	float u2, float v2,
	float u3, float v3)
{
	texturedVertex[0].textureCoords.u = u0;		texturedVertex[0].textureCoords.v = v0;
	texturedVertex[1].textureCoords.u = u1;		texturedVertex[1].textureCoords.v = v1;
	texturedVertex[2].textureCoords.u = u2;		texturedVertex[2].textureCoords.v = v2;
	texturedVertex[3].textureCoords.u = u3;		texturedVertex[3].textureCoords.v = v3;
}

void engine::Sprite::SetTexture(const engine::Texture& texture)
{
	//this->texture = texture;
}


void engine::Sprite::SetAnimation(Animation* animation)
{
	animation = animation;
	previousFrame = std::numeric_limits<unsigned int>::max_digits10;
}

void engine::Sprite::Update()
{
	if (!animation) return;

	animation->Update();

	currentFrame = animation->CurrentFrame();

	if (currentFrame != previousFrame)
	{
		SetTextureCoordinates(animation->GetFrames()[currentFrame].uvCoords[0].u, animation->GetFrames()[currentFrame].uvCoords[0].v,
			animation->GetFrames()[currentFrame].uvCoords[1].u, animation->GetFrames()[currentFrame].uvCoords[1].v,
			animation->GetFrames()[currentFrame].uvCoords[2].u, animation->GetFrames()[currentFrame].uvCoords[2].v,
			animation->GetFrames()[currentFrame].uvCoords[3].u, animation->GetFrames()[currentFrame].uvCoords[3].v);

		previousFrame = currentFrame;
	}
}

//void engine::Sprite::Draw(Renderer& rkRenderer)
//{
//	//rkRenderer.SetCurrentTexture(texture);
//	//rkRenderer.SetMatrix(transformationMatrix);
//	//rkRenderer.Draw(texturedVertex, TRIANGLESTRIP, ARRAY_SIZE(texturedVertex));
//}