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
		friend class Scene;

		static void* operator new(std::size_t size);
		static void* operator new[](std::size_t size) = delete;

	protected:

		static void operator delete(void* ptr) noexcept;
		static void operator delete[](void* ptr) = delete;

		math::Vector3 position;
		math::Vector3 rotation;
		math::Vector3 scale;

		Renderer* renderer = Renderer::Get();


	public:
		
		Entity();
		virtual ~Entity();
	
		virtual void Initialize();

		inline math::Vector3 GetPosition() { return position; }
		inline math::Vector3 GetRotation() { return rotation; }
		inline math::Vector3 GetScale() { return scale; }

		inline virtual void SetPosition(math::Vector3 position) { this->position = position; }
		inline virtual void SetRotation(math::Vector3 rotation) { this->rotation = rotation; }
		inline virtual void SetScale(math::Vector3 scale) { this->scale = scale; }

		virtual void OnCollision();

		virtual void Start() = 0;
		virtual void Update() = 0;

		virtual void Draw() = 0;
	};
}