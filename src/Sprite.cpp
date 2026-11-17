#include "Sprite.h"

engine::Sprite::Sprite() : texture(engine::Texture("res/assets/images.png"))
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

	Setindex({ 0,1,2,2,3,0 });

	//texturedVertex[0].pos.x = -0.5;
	//texturedVertex[0].pos.y = 0.5;
	//texturedVertex[0].pos.z = 0.0f;
	//
	//texturedVertex[1].pos.x = 0.5;
	//texturedVertex[1].pos.y = 0.5;
	//texturedVertex[1].pos.z = 0.0f;
	//
	//texturedVertex[2].pos.x = -0.5;
	//texturedVertex[2].pos.y = -0.5;
	//texturedVertex[2].pos.z = 0.0f;

	//texturedVertex[3].pos.x = 0.5;
	//texturedVertex[3].pos.y = -0.5;
	//texturedVertex[3].pos.z = 0.0f;
	//
	//texturedVertex[0].textureCoords.u = 0.0;
	//texturedVertex[0].textureCoords.v = 0.0f;
	//
	//texturedVertex[1].textureCoords.u = 1.0;
	//texturedVertex[1].textureCoords.v = 0.0;
	//
	//texturedVertex[2].textureCoords.u = 0.0;
	//texturedVertex[2].textureCoords.v = 1.0;
	//
	//texturedVertex[3].textureCoords.u = 1.0;
	//texturedVertex[3].textureCoords.v = 1.0;
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
}

void engine::Sprite::SetTextureCoordinates(math::UVCoords uv1, math::UVCoords uv2, math::UVCoords uv3, math::UVCoords uv4)
{
	SetTextureCoordinates(uv1.u,uv1.v, uv2.u, uv2.v, uv3.u, uv3.v, uv4.u, uv4.v);
}

void engine::Sprite::SetTexture(const engine::Texture& texture)
{
	this->texture = texture;
}

void engine::Sprite::SetAnimation(Animation* animation)
{
	animation = animation;
	previousFrame = std::numeric_limits<unsigned int>::max_digits10;
}

void engine::Sprite::Start()
{
	material = new engine::Material("../res/shaders/VertexTexture.shader", "../res/shaders/FragmentTexture.shader");

	texture = engine::Texture("res/assets/images.png");
	material->SetTexture(&texture);
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