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
	Entity(Mesh& m)
		: transform()
	{
		mesh.vertices = m.vertices;
		mesh.indices = m.indices;
		mesh.textures = m.textures;

		mesh.updateVertices();
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