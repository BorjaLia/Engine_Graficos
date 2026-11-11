#include "Shader.h"
#include "File.h"
#include <GL/glew.h>
#include <iostream>

namespace engine
{
	Shader::Shader(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath) : m_RendererID(0)
	{
		std::string vertexSource;
		std::string fragmentSource;

		if (!File::ReadFile(vertexShaderFilepath, vertexSource))
			std::cout << "Failed to read Vertex Shader: " << vertexShaderFilepath << "\n";
		if (!File::ReadFile(fragmentShaderFilepath, fragmentSource))
			std::cout << "Failed to read Fragment Shader: " << fragmentShaderFilepath << "\n";

		m_RendererID = CreateShader(vertexSource, fragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform(const std::string& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}
	void Shader::SetUniform(const std::string& name, math::Vector4 value)
	{
		glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];

		int location = glGetUniformLocation(m_RendererID, name.c_str());

		if (location == -1)
		{
			std::cout << "\n" << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
		}

		m_UniformLocationCache[name] = location;
		return location;
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "shader failed compilation\n";
			std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader\n";
			std::cout << message << "\n";

			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
}