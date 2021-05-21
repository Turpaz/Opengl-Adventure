#pragma once

#include <glm/glm.hpp>
#include <math.h>

class Transform
{
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
private:
	const glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
public:
	Transform()
	{
		rotation = glm::vec3(0.f, 0.f, 0.f);
		position = glm::vec3(0.f, 0.f, 0.f);
		scale = glm::vec3(1.f, 1.f, 1.f);
	}

	glm::mat4 matrix()
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, this->position);
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, this->scale);
		return model;
	}

	glm::vec3 forward()
	{
		return glm::vec3(sin(rotation.y), -tan(rotation.x), -cos(rotation.y));
	}

	glm::vec3 right()
	{
		return glm::cross(forward(), worldUp);
	}

	glm::vec3 up()
	{
		return worldUp;
	}
};