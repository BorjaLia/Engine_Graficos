#pragma once

#include <vector>

#include "Core.h"

#include "Vector3.h"
#include "Vector2.h"
#include "Vertex.h"
#include "Material.h"
#include "Color.h"
#include "Renderer.h"

#include <glm/glm.hpp>

namespace engine
{
	class ENGINE_API Entity
	{
	private:
	

	protected:
		math::Vector3 position;
		math::Vector3 rotation;
		math::Vector3 scale;

		Renderer* renderer = Renderer::Get();

	public:
		
		Entity();
		~Entity();
	
		virtual void Initialize();

		inline math::Vector3 getPosition() { return position; }
		inline math::Vector3 getRotation() { return rotation; }
		inline math::Vector3 getScale() { return scale; }

		inline void setPosition(math::Vector3 position) { this->position = position; }
		inline void setRotation(math::Vector3 rotation) { this->rotation = rotation; }
		inline void setScale(math::Vector3 scale) { this->scale = scale; }

		virtual void Start() = 0;
		virtual void Update() = 0;

		virtual void Draw() = 0;
	};
}