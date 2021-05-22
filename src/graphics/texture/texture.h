#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "../shader/shader.h"
#include <tools/gldebugging.h>

#define DIFFUSE_TEXTURE_TYPE 0
#define SPECULAR_TEXTURE_TYPE 1

namespace graphics
{
	class Texture
	{
	public:
		GLuint ID;
		char type;
		GLuint unit;
	public:
		Texture(const char* image, char texType = DIFFUSE_TEXTURE_TYPE, bool pixelArt = false, GLuint slot = 31);
		//~Texture() { this->remove(); }

		/*
		Texture& operator=(const Texture&) = delete;
		Texture(Texture& other)
			: ID(sizeof(GLuint)), type(DIFFUSE_TEXTURE_TYPE), unit(0)
		{
			if (this != &other)
			{
				remove();
				ID = other.ID;
				type = other.type;
				unit = other.unit;
				other.ID = sizeof(GLuint);
			}
		}

		Texture& operator=(Texture&& other) noexcept
		{
			if (this != &other)
			{
				remove();
				ID = other.ID;
				type = other.type;
				unit = other.unit;
				other.ID = sizeof(GLuint);
			}

			return *this;
		}*/
		
		void use();
		void unuse();
		void remove();
	};
}