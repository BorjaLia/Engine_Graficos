#include "File.h"

#include <fstream>
#include <sstream>

#include <filesystem>
#include <iostream>

std::string engine::File::rootPath = "";

void engine::File::SetRootPath(const std::string& path)
{
	rootPath = path;

	if (!rootPath.empty() && rootPath.back() != '/' && rootPath.back() != '\\')
	{
		rootPath += '/';
	}

	std::cout << "Root path set to: " << std::filesystem::absolute(rootPath) << std::endl;
}

std::string engine::File::GetAbsolutePath(const std::string& filepath)
{
	if (rootPath.empty()) return filepath;

	return rootPath + filepath;
}

bool engine::File::ReadFile(const std::string& filepath, std::string& outText, FileType type)
{


	std::ifstream file(GetAbsolutePath(filepath));
	if (!file.is_open()) return false;

	std::stringstream buffer;
	buffer << file.rdbuf();
	outText = buffer.str();

	file.close();

	return true;
}

bool engine::File::WriteFile(const std::string& filepath, const std::string& text)
{
	std::ofstream file(GetAbsolutePath(filepath));
	if (!file.is_open()) return false;

	file << text;
	file.close();
	return true;
}
