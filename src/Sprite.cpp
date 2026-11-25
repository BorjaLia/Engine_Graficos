#include "Sprite.h"

engine::Sprite::Sprite() : texture(new engine::Texture("res/assets/spritesheet.png"))
{
	const int vertexAmount = 4;
	math::Vertex vertices[vertexAmount];

	vertices[0].pos = math::Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].pos = math::Vector3(-0.5f, 0.5f, 0.0f);
	vertices[2].pos = math::Vector3(0.5f, 0.5f, 0.0f);
	vertices[3].pos = math::Vector3(0.5f, -0.5f, 0.0f);

	vertices[0].textureCoords = math::UVCoords(0.0f, 0.0f);
	vertices[1].textureCoords = math::UVCoords(0.0f, 1.0f);
	vertices[2].textureCoords = math::UVCoords(1.0f, 1.0f);
	vertices[3].textureCoords = math::UVCoords(1.0f, 0.0f);

	vertices[0].color = utils::Color::white();
	vertices[1].color = utils::Color::white();
	vertices[2].color = utils::Color::white();
	vertices[3].color = utils::Color::white();

	for (int i = 0; i < vertexAmount; i++)
	{
		AddVertex(vertices[i]);
	}

	SetIndex({ 0,1,2,2,3,0 });

	material = new engine::Material("../res/shaders/VertexTexture.shader", "../res/shaders/FragmentTexture.shader");
}

engine::Sprite::~Sprite(void)
{
}

void engine::Sprite::SetTextureCoordinates(float u0, float v0,
	float u1, float v1,
	float u2, float v2,
	float u3, float v3)
{
	if (vertices.size() < 4)
	{
		std::cout << "Cant set the texture coordinates, has less than 4 vertices \n";
		return;
	}

	vertices[0].textureCoords.u = u0;
	vertices[0].textureCoords.v = v0;

	vertices[1].textureCoords.u = u1;
	vertices[1].textureCoords.v = v1;

	vertices[2].textureCoords.u = u2;
	vertices[2].textureCoords.v = v2;

	vertices[3].textureCoords.u = u3;
	vertices[3].textureCoords.v = v3;

	UpdateBufferData();
}

void engine::Sprite::SetTextureCoordinates(math::UVCoords uv1, math::UVCoords uv2, math::UVCoords uv3, math::UVCoords uv4)
{
	SetTextureCoordinates(uv1.u, uv1.v, uv2.u, uv2.v, uv3.u, uv3.v, uv4.u, uv4.v);
}

void engine::Sprite::SetTexture(engine::Texture& texture)
{
	this->texture = &texture;
	material->SetTexture(this->texture);
}

void engine::Sprite::SetAnimation(Animation* animation)
{
	this->animation = animation;
	previousFrame = std::numeric_limits<unsigned int>::max_digits10;
}

void engine::Sprite::Start()
{
	//texture = engine::Texture("res/assets/images.png");
	material->SetTexture(texture);
}

void engine::Sprite::Update()
{
	if (!animation) return;

	animation->Update();

	currentFrame = animation->CurrentFrame();

	if (currentFrame != previousFrame)
	{
		math::UVCoords* uvs = animation->GetFrames()[currentFrame].uvCoords;

		SetTextureCoordinates(
			(isFlippedX ? uvs[3].u : uvs[0].u), (isFlippedY ? uvs[1].v : uvs[0].v),
			(isFlippedX ? uvs[2].u : uvs[1].u), (isFlippedY ? uvs[0].v : uvs[1].v),
			(isFlippedX ? uvs[1].u : uvs[2].u), (isFlippedY ? uvs[3].v : uvs[2].v),
			(isFlippedX ? uvs[0].u : uvs[3].u), (isFlippedY ? uvs[2].v : uvs[3].v));

		previousFrame = currentFrame;
	}
}