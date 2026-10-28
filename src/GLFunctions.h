#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x)
#define GLCall(x)

static void GLClearError();
static bool GLLogCall(const char* function, const char* file,int line);