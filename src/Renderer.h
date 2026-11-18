#pragma once

#include "Window.h"
#include "Vertex.h"
#include "Material.h"

#include <glm/glm.hpp>
#include "GL/GL.h"

namespace engine
{
	/// The class that draws to the screen
	/// @ingroup Rnderer

	class Renderer
	{
	protected:

		Renderer(){}

		static Renderer* instance;

		Window* window = nullptr;

	public:

        Renderer(Renderer& other) = delete;
        void operator=(const Renderer&) = delete;

        static Renderer* Get();

		int Initialize(Window& window);

		void Update();
		void Draw(unsigned int& vao, unsigned int& ibo, glm::mat4 trs, Material* material, int glDrawType = GL_TRIANGLES);
		int Shutdown();

		math::Vector2 GetSize() { return window->GetSize(); };

		glm::mat4 GetMPVMat4x4() const { return mvp; };
		glm::mat4 GetProjectionMat4x4() const { return proj; };
		glm::mat4 GetViewMat4x4() const { return view; };

		void GenerateBuffers(std::vector<math::Vertex> vertices, std::vector<unsigned int> indices,
			unsigned int* vao, unsigned int* vbo, unsigned int* ibo);

		void UpdateBuffers(std::vector<math::Vertex> vertices, unsigned int* vbo);

	private:

		glm::mat4 proj;
		glm::mat4 view;
		glm::mat4 mvp;
	};
}