#include "Entity.h"

engine::Entity::Entity()
{
	position = math::Vector3(0.0f, 0.0f, 0.0f);
	rotation = math::Vector3(0.0f, 1.0f, 0.0f);
	scale = math::Vector3(1.0f, 1.0f, 1.0f);

	buffer = 0;
}

engine::Entity::~Entity()
{
}

void engine::Entity::Initialize()
{
	//tint = utils::Color::white();
	//
	//vertices.push_back(math::Vertex(math::Vector2(-0.5f, -0.5f), utils::Color::red()));
	//vertices.push_back(math::Vertex(math::Vector2(0.0f, 0.5f), utils::Color::green()));
	//vertices.push_back(math::Vertex(math::Vector2(0.5f, -0.5f), utils::Color::blue()));

	//vertices.push_back(math::Vertex(math::Vector2(-0.5f, -0.5f), utils::Color::red()));
	//vertices.push_back(math::Vertex(math::Vector2(-0.5f, 0.5f), utils::Color::green()));
	//vertices.push_back(math::Vertex(math::Vector2(0.5f, 0.5f), utils::Color::blue()));
	//vertices.push_back(math::Vertex(math::Vector2(0.5f, -0.5f), utils::Color::green()));

	for (math::Vertex& v : vertices)
	{
		v.pos.x += position.x;
		v.pos.y += position.y;

		v.color.r *= (tint.r / 255.0f);
		v.color.g *= (tint.g / 255.0f);
		v.color.b *= (tint.b / 255.0f);
		v.color.a *= (tint.a / 255.0f);
	}

	//indices = { 0,1,2 };
	//indices = { 0,1,2,2,3,0 };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(math::Vertex), vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, color));

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void engine::Entity::AddVertex(math::Vertex v)
{
	vertices.push_back(v);
}

void engine::Entity::AddIndex(int i)
{
	indices.push_back(i);
}

void engine::Entity::Setindex(std::vector<int> indices)
{
	for (int i : indices)
	{
		this->indices.push_back(i);
	}
}

