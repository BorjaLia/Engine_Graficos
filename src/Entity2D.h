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
		void Setindex(std::vector<int> indices);

		void UpdateBufferData();

		Material* GetMaterial() const { return material; }
		inline Bounds getBounds() { return AABB; }

		void setPosition(math::Vector3 position) override;
		void setRotation(math::Vector3 rotation) override;
		void setScale(math::Vector3 scale) override;
		inline void setBounds(Bounds bounds) { AABB = bounds; }

		void updateTransform();

		virtual void Draw() override;

		inline utils::Color getTint() { return tint; }
		inline void setTint(utils::Color tint) { this->tint = tint; }


		// Inherited via Entity
		void Start() override;

		void Update() override;

	};
}