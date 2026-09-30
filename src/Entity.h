#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "Renderer.h"

namespace engine
{
	class Entity
	{
	private:
	
		math::Vector3 position;
		math::Vector3 rotation;
		math::Vector3 scale;

		Renderer* renderer = Renderer::Get();
	
		unsigned int buffer;

	public:
		
		Entity();
		~Entity();
	
		void Initialize();

		inline math::Vector3 getPosition() { return position; }
		inline math::Vector3 getRotation() { return rotation; }
		inline math::Vector3 getScale() { return scale; }

		inline void setPosition(math::Vector3 position) { this->position = position; }
		inline void setRotation(math::Vector3 rotation) { this->rotation = rotation; }
		inline void setScale(math::Vector3 scale) { this->scale = scale; }

		virtual void Draw() = 0;
	};
}