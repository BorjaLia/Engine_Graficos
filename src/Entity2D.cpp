#include "Entity2D.h"

engine::Entity2D::Entity2D()
{
	material = nullptr;
	vbo = 0;
	ibo = 0;
	vao = 0;
	trs = 0;
}

engine::Entity2D::~Entity2D()
{
	delete material;
}

void engine::Entity2D::Initialize()
{
	for (math::Vertex& v : vertices)
	{
		v.pos.x += position.x;
		v.pos.y += position.y;

		v.color.r *= (tint.r / 255.0f);
		v.color.g *= (tint.g / 255.0f);
		v.color.b *= (tint.b / 255.0f);
		v.color.a *= (tint.a / 255.0f);
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(math::Vertex), vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, textureCoords));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, color));

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void engine::Entity2D::AddVertex(math::Vertex v)
{
	vertices.push_back(v);
}

void engine::Entity2D::AddIndex(int i)
{
	indices.push_back(i);
}

void engine::Entity2D::Setindex(std::vector<int> indices)
{
	for (int i : indices)
	{
		this->indices.push_back(i);
	}
}