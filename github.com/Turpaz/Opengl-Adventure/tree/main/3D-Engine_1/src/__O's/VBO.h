#pragma once

#include <vector>
#include <glad/glad.h>
#include <engine/vertex.h>

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO(std::vector<Vertex>& vertices);
	~VBO() { this->remove(); }

	// Binds the VBO
	void use();
	// Unbinds the VBO
	void unuse();
	// Deletes the VBO
	void remove();
};