#pragma once

#include <string>
#include <vector>

#include "vertex.h"
#include <__O's/VAO.h>
#include <__O's/EBO.h>
#include <graphics/camera.h>
#include <graphics/texture/texture.h>

namespace graphics
{
	class Mesh
	{
	public:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture> textures;

		VAO vao;
	public:
		Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
			: vertices(vertices), indices(indices), textures(textures)
		{
			updateVertices();
		}
		Mesh(Vertex* verts, GLsizeiptr vsize, GLuint* inds, GLsizeiptr isize, Texture* texs, GLsizeiptr tsize)
		{
			vertices = std::vector<Vertex>(verts, verts + vsize / sizeof(Vertex));
			indices = std::vector<GLuint>(inds, inds + isize / sizeof(GLuint));
			textures = std::vector<Texture>(texs, texs + tsize / sizeof(Texture));

			updateVertices();
		}
		Mesh(Vertex*& verts, GLuint*& inds, Texture*& texs)
		{
			vertices = std::vector<Vertex>(verts, verts + sizeof(verts) / sizeof(Vertex));
			indices = std::vector<GLuint>(inds, inds + sizeof(inds) / sizeof(GLuint));
			textures = std::vector<Texture>(texs, texs + sizeof(textures) / sizeof(Texture));

			updateVertices();
		}
		Mesh()
		{
			updateVertices();
		}

		void updateVertices()
		{
			vao.use();
			VBO vbo(vertices);
			EBO ebo(indices);
			vao.linkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
			vao.linkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
			vao.linkAttrib(vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
			vao.linkAttrib(vbo, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
			vao.unuse();
			vbo.unuse();
			ebo.unuse();
		}

		void render(Shader& shader, Camera& camera, glm::mat4 matrix = glm::mat4(1.0f))
		{
			shader.use();
			vao.use();

			unsigned int numDiffuse = 0;
			unsigned int numSpecular = 0;

			for (unsigned int i = 0; i < textures.size(); i++)
			{
				std::string num;
				std::string type = textures[i].type;
				if (type == "diffuse")
				{
					num = std::to_string(numDiffuse++);
				}
				else if (type == "specular")
				{
					num = std::to_string(numSpecular++);
				}
				//textures[i].texUnit(shader, (type + num).c_str(), i);
				textures[i].texUnit(shader, (type + num).c_str(), i);
				textures[i].use();
			}

			// Take care of the camera Matrix
			shader.set3f("camPos", camera.transform.position.x, camera.transform.position.y, camera.transform.position.z);
			camera.matrix(shader, "camMatrix");

			shader.setMat4("model", 1, GL_FALSE, glm::value_ptr(matrix));

			// Draw the actual mesh
			glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
		}
	};
}