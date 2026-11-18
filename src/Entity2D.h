#pragma once
#include "Entity.h"
#include "Bounds.h"

namespace engine
{
	class ENGINE_API Entity2D : public Entity
	{
	private:
	protected:

		std::vector<unsigned int> indices;
		std::vector<math::Vertex> vertices;

		unsigned int vbo;
		unsigned int ibo;
		unsigned int vao;

		glm::mat4 trs;
		Material* material;
		Bounds AABB;

		utils::Color tint;

	public:

		Entity2D();
		~Entity2D();

		void Initialize() override;

		void AddVertex(math::Vertex v);
		void AddIndex(int i);
		void SetIndex(std::vector<int> indices);

		void UpdateBufferData();

		Material* GetMaterial() const { return material; }
		inline Bounds GetBounds() { return AABB; }

		void SetPosition(math::Vector3 position) override;
		void SetRotation(math::Vector3 rotation) override;
		void SetScale(math::Vector3 scale) override;
		inline void setBounds(Bounds bounds) { AABB = bounds; }

		void UpdateTransform();

		virtual void Draw() override;

		inline utils::Color GetTint() { return tint; }
		inline void SetTint(utils::Color tint) { this->tint = tint; }


		// Inherited via Entity
		void Start() override;

		void Update() override;

	};
}