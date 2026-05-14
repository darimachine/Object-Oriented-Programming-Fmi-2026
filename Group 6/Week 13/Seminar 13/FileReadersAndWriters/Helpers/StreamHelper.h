#pragma once
#include <iostream>
#include <fstream>
namespace StreamHelper {

	int getCharCount(std::ifstream& ifs, char ch);
	size_t getFileSize(std::ifstream& ifs);
}

