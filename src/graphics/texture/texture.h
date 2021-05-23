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
		~Texture() { this->remove(); }

		// Making the copy constructor (and operator) call the move one instead
		// Which is almost the same except it's telling it to not delete the texture,
		// So when copying the texture, and the old one runs out of scope, the old one doesn't delete the texture buffer
		Texture(const Texture& other) : Texture((Texture&&)other) {}
		Texture(Texture&& other) noexcept
			: ID(), type(), unit()
		{
			if (this != &other)
			{
				remove();
				ID = other.ID;
				type = other.type;
				unit = other.unit;
				other.copied();
			}
		}
		Texture& operator=(const Texture& other) { return operator=((Texture&&)other); }
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
		}
		
		void use() const;
		void unuse() const;
		void remove() const;
		void copied();
	};
}