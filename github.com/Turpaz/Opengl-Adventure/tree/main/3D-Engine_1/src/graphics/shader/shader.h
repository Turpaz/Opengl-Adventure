#pragma once

#include <glad/glad.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <glm/glm.hpp>

namespace graphics
{
	class Shader
	{
	public:
		GLuint ID;
	public:
		Shader(const char* vertexFile, const char* fragmentFile);
		Shader() : ID(0) {}
		~Shader();

		inline void use() { glUseProgram(this->ID); }
		inline void unuse() { glDeleteProgram(this->ID); }

		// Uniforms
		void set4f(const char* name, float x, float y, float z, float w)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform4f(loc, x, y, z, w);
		}
		void set4f(const char* name, glm::vec4 x)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform4f(loc, x.x, x.y, x.z, x.w);
		}
		void set3f(const char* name, float x, float y, float z)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform3f(loc, x, y, z);
		}
		void set3f(const char* name, glm::vec3 x)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform3f(loc, x.x, x.y, x.z);
		}
		void set2f(const char* name, float x, float y)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform2f(loc, x, y);
		}
		void set2f(const char* name, glm::vec2 x)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform2f(loc, x.x, x.y);
		}
		void set1f(const char* name, float x)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform1f(loc, x);
		}
		void set1i(const char* name, int x)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniform1i(loc, x);
		}
		template <typename T>
		void setMat4(const char* name, unsigned int x, bool y, T z)
		{
			GLuint loc = glGetUniformLocation(ID, name);
			use();
			glUniformMatrix4fv(loc, x, y, z);
		}
	private:
		void compileErrors(unsigned int shader, const char* type);
	};
}