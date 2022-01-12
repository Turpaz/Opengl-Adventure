#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(x) GLDebug::GLClearError();\
	x;\
	ASSERT(GLDebug::GLLogCall(#x, __FILE__, __LINE__));

class GLDebug
{
public:
	static void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	static bool GLLogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << "): in " << function << ", " << file << ":" << line << std::endl;
			return false;
		}
		return true;
	}
};