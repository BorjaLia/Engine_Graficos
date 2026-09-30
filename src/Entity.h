#pragma once

#include <vector>

#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"
#include "Vertex.h"
#include "Renderer.h"

namespace engine
{
	class Entity
	{
	private:
	
		math::Vector3 position;
		math::Vector3 rotation;
		math::Vector3 scale;

		utils::Color tint;

		Renderer* renderer = Renderer::Get();
	
		unsigned int buffer;

	protected:

		unsigned int ibo;
		unsigned int vao;
		std::vector<unsigned int> indices;
		std::vector<math::Vertex> vertices;

	public:
		
		Entity();
		~Entity();
	
		void Initialize();

		inline math::Vector3 getPosition() { return position; }
		inline math::Vector3 getRotation() { return rotation; }
		inline math::Vector3 getScale() { return scale; }
		inline utils::Color getTint() { return tint; }

		inline void setPosition(math::Vector3 position) { this->position = position; }
		inline void setRotation(math::Vector3 rotation) { this->rotation = rotation; }
		inline void setScale(math::Vector3 scale) { this->scale = scale; }
		inline void setTint(utils::Color tint) { this->tint = tint; }

		virtual void Draw() = 0;
	};
}