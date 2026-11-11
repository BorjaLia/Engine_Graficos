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
	renderer->GenerateBuffers(vertices, indices, &vao, &vbo, &ibo);
}

void engine::Entity2D::Draw()
{
	std::vector<math::Vertex> newV = vertices;

	float s = sin(rotation.x);
	float c = cos(rotation.x);

	float x, y;

	for (math::Vertex& v : newV)
	{
		v.pos.x *= scale.x;
		v.pos.y *= scale.y;

		x = v.pos.x;
		y = v.pos.y;

		v.pos.x = x * c - y * s;
		v.pos.y = x * s + y * c;

		v.pos.x += position.x;
		v.pos.y += position.y;
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, newV.size() * sizeof(math::Vertex), newV.data(), GL_STATIC_DRAW);

	glBindVertexArray(vao);

	if (material)
	{
		material->Bind();
	}

	Renderer::Get()->Draw(indices.size());

	if (material)
	{
		material->Unbind();
	}

	glBindVertexArray(0);
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