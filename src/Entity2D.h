#pragma once
#include "Entity.h"

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

		void setPosition(math::Vector3 position) override;
		void setRotation(math::Vector3 rotation) override;
		void setScale(math::Vector3 scale) override;

		void updateTransform();

		virtual void Draw() override;

		inline utils::Color getTint() { return tint; }
		inline void setTint(utils::Color tint) { this->tint = tint; }

	};
}