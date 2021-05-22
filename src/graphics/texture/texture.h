#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "../shader/shader.h"
#include <tools/gldebugging.h>

namespace graphics
{
	class Texture
	{
	public:
		GLuint ID;
		const char* type;
		GLuint unit;
	public:
		Texture(const char* image, const char* texType = "diffuse", bool pixelArt = false, GLuint slot = 31);
		~Texture() { this->remove(); }
		
		void use();
		void unuse();
		void remove();
	};
}