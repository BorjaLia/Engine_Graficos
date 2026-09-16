#include "Shader.h"

#include "Window.h"
#include "File.h"
#include <iostream>

unsigned int engine::CompileShader(unsigned int type, const std::string& source)
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
		std::cout << "shader failed compilation" << std::endl;
		std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id);
		return 0;
	}

	return id;
}

bool engine::CreateShaderFromFile(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath)
{
	std::string vertexShader;
	std::string fragmentShader;

	if (!engine::File::ReadFile(vertexShaderFilepath, vertexShader)) return 0;
	if (!engine::File::ReadFile(fragmentShaderFilepath, fragmentShader)) return 0;

	unsigned int shader = CreateShader(vertexShader,fragmentShader);
	glUseProgram(shader);

	return true;
}

int engine::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER,vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER,fragmentShader);

	glAttachShader(program,vs);
	glAttachShader(program,fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return 1;
}
