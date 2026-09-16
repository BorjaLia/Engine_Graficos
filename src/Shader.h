#pragma once

#include <string>

static unsigned int CompileShader(unsigned int type, const std::string& source);

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);