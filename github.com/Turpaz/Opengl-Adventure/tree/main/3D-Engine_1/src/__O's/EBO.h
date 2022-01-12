#pragma once

#include <glad/glad.h>
#include <vector>

class EBO
{
public:
	// ID reference of Elements Buffer Object
	GLuint ID;
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);
	EBO(std::vector<GLuint>& indices);
	~EBO() { this->remove(); }

	// Binds the EBO
	void use();
	// Unbinds the EBO
	void unuse();
	// Deletes the EBO
	void remove();
};