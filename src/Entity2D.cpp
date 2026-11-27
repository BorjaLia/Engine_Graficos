#include "Entity2D.h"
#include <glm/gtc/matrix_transform.hpp>

engine::Entity2D::Entity2D()
{
	AABB = Bounds(math::Vector3(-1.0f,-1.0f,-1.0f), math::Vector3(1.0f, 1.0f, 1.0f));
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

void engine::Entity2D::OnCollision()
{
}

void engine::Entity2D::Draw()
{
	Renderer::Get()->Draw(vao, ibo, trs, material);
}

void engine::Entity2D::Start()
{
}

void engine::Entity2D::Update()
{
}

void engine::Entity2D::AddVertex(math::Vertex v)
{
	vertices.push_back(v);
}

void engine::Entity2D::AddIndex(int i)
{
	indices.push_back(i);
}

void engine::Entity2D::SetIndex(std::vector<int> indices)
{
	for (int i : indices)
	{
		this->indices.push_back(i);
	}
}

void engine::Entity2D::UpdateBufferData()
{
	renderer->UpdateBuffers(vertices,&vbo);
}

void engine::Entity2D::SetPosition(math::Vector3 position)
{
	this->position = position;
	UpdateTransform();
}

void engine::Entity2D::SetRotation(math::Vector3 rotation)
{
	this->rotation = rotation;
	UpdateTransform();
}

void engine::Entity2D::SetScale(math::Vector3 scale)
{
	this->scale = scale;
	UpdateTransform();
}

void engine::Entity2D::OnCollision(Entity2D* other)
{
}

void engine::Entity2D::UpdateTransform()
{
	trs = glm::mat4(1.0f);

	trs = glm::translate(trs, glm::vec3(position.x, position.y, position.z));

	trs = glm::rotate(trs, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	trs = glm::rotate(trs, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	trs = glm::rotate(trs, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	trs = glm::scale(trs, glm::vec3(scale.x, scale.y, scale.z));
}




