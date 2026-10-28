#include "Texture.h"

engine::Texture::Texture(const std::string path): filePath(path),localBuffer(nullptr),size(math::Vector2(0.0f,0.0f)),BPP(0)
{
	GLCall();
}

engine::Texture::~Texture()
{
}

void engine::Texture::Bind(unsigned int slot) const
{
}

void engine::Texture::Unbind()
{
}