#pragma once

#include "transform.h"
#include "mesh.h"

using namespace graphics;

class Entity
{
public:
	Camera* mainCamera;
	Shader* mainShader;
public:
	Transform transform;
	Mesh mesh;
public:
	Entity() : mesh(1) {}
	Entity(Mesh& m)
		: transform()
	{
		mesh.vertices = m.vertices;
		mesh.indices = m.indices;
		mesh.textures = m.textures;

		mesh.updateVertices();
	}

	Entity& operator=(const Entity& other)
	{
		this->transform = other.transform;
		this->mesh = other.mesh;
		this->mainCamera = other.mainCamera;
		this->mainShader = other.mainShader;

		return *this;
	}

	void render()
	{
		mesh.render(*Entity::mainShader, *Entity::mainCamera, transform.matrix());
	}

	void render(Shader& shader, Camera& camera)
	{
		mesh.render(shader, camera, transform.matrix());
	}
};