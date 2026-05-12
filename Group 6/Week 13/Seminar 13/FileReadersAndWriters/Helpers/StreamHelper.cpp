#include "StreamHelper.h"

int StreamHelper::getCharCount(std::ifstream& ifs, char ch)
{
	int counter = 0;
	size_t currentPos = ifs.tellg();
	ifs.seekg(0);
	while (true) {
		char current = ifs.get();
		if (ifs.eof()) {
			break;
		}
		if (current == ch) {
			counter++;
		}
	}
	ifs.clear();
	ifs.seekg(currentPos);
	return counter;
}

size_t StreamHelper::getFileSize(std::ifstream& ifs)
{
	size_t currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t fileSize = ifs.tellg();

	ifs.seekg(currentPos);
	return fileSize;
}
