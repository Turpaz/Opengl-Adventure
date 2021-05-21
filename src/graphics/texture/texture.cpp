#include "texture.h"

namespace graphics
{
	unsigned char nrOtextures = 0;

	Texture::Texture(const char* image, const char* texType, bool pixelArt, GLuint slot)
		: type(texType)
	{
		if (slot == sizeof(GLuint))
			slot = nrOtextures++;

		int widthImg, heightImg, numColCh;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, STBI_rgb_alpha);

		glGenTextures(1, &ID);
		glActiveTexture(GL_TEXTURE0 + slot);
		unit = slot;
		glBindTexture(GL_TEXTURE_2D, ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, pixelArt ? GL_NEAREST : GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, pixelArt ? GL_NEAREST : GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		if (numColCh == 4)
			glTexImage2D
			(GL_TEXTURE_2D,0,GL_RGBA,widthImg,heightImg,0,GL_RGBA,GL_UNSIGNED_BYTE,bytes);
		else if (numColCh == 3)
			glTexImage2D
			(GL_TEXTURE_2D,0,GL_RGBA,widthImg,heightImg,0,GL_RGB,GL_UNSIGNED_BYTE,bytes);
		else if (numColCh == 1)
			glTexImage2D
			(GL_TEXTURE_2D,0,GL_RGBA,widthImg,heightImg,0,GL_RED,GL_UNSIGNED_BYTE,bytes);
		else
			throw std::invalid_argument("Automatic Texture type recognition failed");

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(bytes);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
	{
		shader.set1i("uniform", unit);
	}

	void Texture::use()
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, ID);
	}

	void Texture::unuse()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::remove()
	{
		glDeleteTextures(1, &ID);
	}
}