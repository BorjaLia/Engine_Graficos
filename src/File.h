#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace engine
{

	enum class FileType
	{
		TEXT,
		BINARY
	};

	/// functions for reading and writing files.
	class File
	{
	public:
		static void SetRootPath(const std::string& path);
		static std::string GetAbsolutePath(const std::string& filepath);

		static bool ReadFile(const std::string& filepath, std::string& outText, FileType type = FileType::TEXT);

		static bool WriteFile(const std::string& filepath, const std::string& text);

	private:
		static std::string rootPath;
	};
}