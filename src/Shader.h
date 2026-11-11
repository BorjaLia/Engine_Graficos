#pragma once

#include <string>
#include <unordered_map>

#include "Vector4.h"

namespace engine
{
	class Shader
	{
	private:
		unsigned int m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;

	public:
		Shader(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetUniform(const std::string& name, int value);
		void SetUniform(const std::string& name, math::Vector4 value);

	private:
		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
		int GetUniformLocation(const std::string& name);
	};
}