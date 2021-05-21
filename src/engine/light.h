#pragma once

#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include "transform.h"
#include <graphics/shader/shader.h>

#define POINT_LIGHT_TYPE (char)0
#define DIRECTIONAL_LIGHT_TYPE (char)1
#define SPOT_LIGHT_TYPE (char)2

namespace engine
{
	unsigned int lightCount = 0;
}

typedef struct light
{
	int type; // 0 = point, 1 = dir, 2 = spot

	glm::vec3 position;
	glm::vec4 color; // vec4(1.f, 1.f, 1.f, 1.f)
	glm::vec3 direction; // vec3(1.f, 1.f, 0.f)

	float outerCone; // 0.90f
	float innerCone; // 0.95f

	float intenAdd; // 1.0f
	float ambient; // 0.2f
	float specular; // 0.5f
} light;

class Light
{
public:
	Transform transform;

	char type;
	glm::vec4 color;

	float intensity = 1.0f;
	float ambient = 0.2f;
	float specular = 0.5f;

	float outerCone = 0.90f;
	float innerCone = 0.95f;
private:
	unsigned int ID;
	Shader* shader;
public:
	Light(Shader& sh, char t = POINT_LIGHT_TYPE, glm::vec3 pos = glm::vec3(0.f), glm::vec3 rot = glm::vec3(0.f), glm::vec4 col = glm::vec4(1.f))
		: type(t), color(col), shader(&sh)
	{
		transform.position = pos;
		transform.rotation = rot;

		ID = engine::lightCount;
		engine::lightCount++;

		sendUniforms();
	}

	void render()
	{
		sendUniforms();
	}
private:
	void sendUniforms()
	{
		(*shader).set1i("nrOfLights", engine::lightCount);

		light _light;

		_light.type = type;

		_light.position = transform.position;
		_light.color = this->color;
		_light.direction = transform.forward();

		_light.outerCone = this->outerCone;
		_light.innerCone = this->innerCone;

		_light.intenAdd = this->intensity;
		_light.ambient = this->ambient;
		_light.specular = this->specular;

		sendLightUniform(_light);
	}

	void sendLightUniform(light& l)
	{
		(*shader).set1i(("lights[" + std::to_string(this->ID) + "].type").c_str(), l.type);
		
		(*shader).set3f(("lights[" + std::to_string(this->ID) + "].position").c_str(), l.position);
		(*shader).set4f(("lights[" + std::to_string(this->ID) + "].color").c_str(), l.color);
		(*shader).set3f(("lights[" + std::to_string(this->ID) + "].direction").c_str(), l.direction);
		
		(*shader).set1f(("lights[" + std::to_string(this->ID) + "].outerCone").c_str(), l.outerCone);
		(*shader).set1f(("lights[" + std::to_string(this->ID) + "].innerCone").c_str(), l.innerCone);
		
		(*shader).set1f(("lights[" + std::to_string(this->ID) + "].intenAdd").c_str(), l.intenAdd);
		(*shader).set1f(("lights[" + std::to_string(this->ID) + "].ambient").c_str(), l.ambient);
		(*shader).set1f(("lights[" + std::to_string(this->ID) + "].specular").c_str(), l.specular);
	}
};