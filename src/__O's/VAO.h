#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	// Constructor that generates a VAO ID
	VAO();
	~VAO() { this->remove(); }

	// Links a VBO Attribute such as a position or color to the VAO
	void linkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	// Binds the VAO
	void use();
	// Unbinds the VAO
	void unuse();
	// Deletes the VAO
	void remove();
};
