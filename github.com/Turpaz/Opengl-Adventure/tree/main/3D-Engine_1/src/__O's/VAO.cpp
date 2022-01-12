#include "VAO.h"

// Constructor that generates a VAO ID
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

// Links a VBO Attribute such as a position or color to the VAO
void VAO::linkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.use();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, (GLsizei)stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.unuse();
}

// Binds the VAO
void VAO::use()
{
	glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::unuse()
{
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::remove()
{
	glDeleteVertexArrays(1, &ID);
}