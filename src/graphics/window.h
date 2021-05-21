#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define FULLSCREEN 0

namespace graphics
{
	class Window
	{
	private:
		GLFWwindow* m_Window;
		int m_Width;
		int m_Height;
		char* m_Name;
	public:
		Window(int w = 960, int h = 540, const char* n = __FILE__)
			: m_Width(w), m_Height(h), m_Name((char*)n)
		{
			init();

			// Settings
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			glFrontFace(GL_CCW);
		}
		~Window()
		{
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

		// Getters
		int width()
		{
			glfwGetWindowSize(m_Window, &m_Width, &m_Height);

			return m_Width;
		}
		int height()
		{
			glfwGetWindowSize(m_Window, &m_Width, &m_Height);

			return m_Height;
		}
		float widthf()
		{
			glfwGetWindowSize(m_Window, &m_Width, &m_Height);

			return (float)m_Width;
		}
		float heightf()
		{
			glfwGetWindowSize(m_Window, &m_Width, &m_Height);

			return (float)m_Height;
		}
		char* name()
		{
			return m_Name;
		}
		GLFWwindow* window()
		{
			return m_Window;
		}

		// Functions
		bool closed()
		{
			return glfwWindowShouldClose(m_Window);
		}

		void update()
		{
			
		}
	private:
		void init()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, FULLSCREEN, NULL);
			if (m_Window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				exit(-1);
			}
			glfwMakeContextCurrent(m_Window);

			glfwSetFramebufferSizeCallback(m_Window, this->framebuffer_size_callback);

			gladLoadGL();

			glViewport(0, 0, m_Width, m_Height);
		}

		static void framebuffer_size_callback(GLFWwindow* window, int w, int h)
		{
			glViewport(0, 0, w, h);
		}
	};
}