#pragma once

#include "Renderer.h"
#include "Vector2.h"

#include <string>

namespace engine
{
	class Texture
	{
	public:
		Texture(const std::string path);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind();

		inline math::Vector2 GetSize() { return size; };

	private:

		unsigned int rendererId =;
		std::string filePath = "";

		unsigned char* localBuffer;
		math::Vector2 size;
		int BPP;

	};
}