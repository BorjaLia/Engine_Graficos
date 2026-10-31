#include "Texture.h"

#include "stb/stb_image.h"

engine::Texture::Texture(const std::string path) : filePath(path), localBuffer(nullptr), size(math::Vector2(0.0f, 0.0f)), BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	int tempX = 0, tempY = 0;

	std::cout << "Looking at path: " << path;

	localBuffer = stbi_load(path.c_str(), &tempX, &tempY, &BPP, 4);

	if (!localBuffer)
	{
		std::cout << "\n No image loaded! Reason: " << stbi_failure_reason() << "\n";
	}

	size = math::Vector2(tempX, tempY);

	glGenTextures(1, &rendererId);
	glBindTexture(GL_TEXTURE_2D, rendererId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

//glTexImage1D(GL_TEXTURE_2D, 0, GL_RGBA8, size.x, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);

	if (localBuffer) // removes local data 
	{
		stbi_image_free(localBuffer);
	}
}

engine::Texture::~Texture()
{
	///*GLCall(*/glDeleteTextures(1, (GLuint)rendererId);
}

void engine::Texture::Bind(unsigned int slot) const
{
	/*GLCall(*/glActiveTexture(GL_TEXTURE0 + slot);
	/*GLCall(*/glBindBuffer(GL_TEXTURE_2D, rendererId);
}

void engine::Texture::Unbind()
{
	/*GLCall(*/glBindTexture(GL_TEXTURE_2D, 0);
}