#pragma once
#include "Core.h"
#include <string>

#include "Color.h"

namespace engine
{
	class Shader;
	class Texture;

	class ENGINE_API Material
	{
	private:
		Shader* m_Shader;
		Texture* m_Texture;
		utils::Color m_Tint;

	public:
		Material(const std::string& vertexPath, const std::string& fragmentPath);
		~Material();

		void SetTexture(Texture* texture);
		void SetTint(utils::Color color);

		Shader* GetShader() const;

		void Bind() const;
		void Unbind() const;
	};
}