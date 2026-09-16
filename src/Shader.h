#pragma once

#include <string>

namespace engine
{
	static unsigned int CompileShader(unsigned int type, const std::string& source);

	bool CreateShaderFromFile(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);

	static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
}