#include "Entity2D.h"
#include <glm/gtc/matrix_transform.hpp>

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
	//float s = sin(rotation.x);
	//float c = cos(rotation.x);

	//float x, y;

	//for (math::Vertex& v : newV)
	//{
	//	v.pos.x *= scale.x;
	//	v.pos.y *= scale.y;

	//	x = v.pos.x;
	//	y = v.pos.y;

	//	v.pos.x = x * c - y * s;
	//	v.pos.y = x * s + y * c;

	//	v.pos.x += position.x;
	//	v.pos.y += position.y;
	//}

	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, newV.size() * sizeof(math::Vertex), newV.data(), GL_STATIC_DRAW);

	Renderer::Get()->Draw(vao, ibo, trs, material);
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

void engine::Entity2D::setPosition(math::Vector3 position)
{
	this->position = position;
	updateTransform();
}

void engine::Entity2D::setRotation(math::Vector3 rotation)
{
	this->rotation = rotation;
	updateTransform();
}

void engine::Entity2D::setScale(math::Vector3 scale)
{
	this->scale = scale;
	updateTransform();
}

void engine::Entity2D::updateTransform()
{
	trs = glm::mat4(1.0f);

	trs = glm::translate(trs, glm::vec3(position.x, position.y, position.z));

	trs = glm::rotate(trs, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	trs = glm::rotate(trs, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	trs = glm::rotate(trs, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	trs = glm::scale(trs, glm::vec3(scale.x, scale.y, scale.z));
}




