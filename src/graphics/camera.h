#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include "shader/shader.h"
#include "window.h"

#include <engine/transform.h>

using Shader = graphics::Shader;
using Window = graphics::Window;

class Camera
{
private:
	Window& m_window;
public:
	float fov, near, far;
	bool orthographic_view;
	Transform transform;
public:
	Camera()
		: m_window((Window&)Window()), fov(90.f), near(0.1f), far(100.f), orthographic_view(false)
	{
		transform.position = glm::vec3(0.f, 0.f, 0.f);
	}
	Camera(Window& win, glm::vec3 p = glm::vec3(0.f))
		: m_window(win), fov(90.f), near(0.1f), far(100.f), orthographic_view(false)
	{
		transform.position = p;
	}

	void matrix(Shader& shader, const char* uniform)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		view = glm::lookAt(transform.position, transform.position + transform.forward(), transform.up());

		if (orthographic_view) // false by default
			proj = glm::ortho(0.f, m_window.widthf() / m_window.heightf(), 0.f, 1.f, near, far);
		else
			proj = glm::perspective(glm::radians(fov / 2.f), m_window.widthf() / m_window.heightf(), near, far);

		shader.setMat4(uniform, 1, GL_FALSE, glm::value_ptr((proj * view)));
	}
};