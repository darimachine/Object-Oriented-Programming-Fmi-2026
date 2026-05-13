#include "BinaryFileReader.h"
#include "StreamHelper.h"
BinaryFileReader::BinaryFileReader(const MyString& fileName) : FileReader(fileName)
{
}

void BinaryFileReader::read(int*& arr, size_t& size) const
{
	std::ifstream ifs(fileName.c_str(), std::ios::binary);
	if (!ifs.is_open()) {
		return;
	}
	delete[] arr;
	size_t fileSize = StreamHelper::getFileSize(ifs);
	size = fileSize / sizeof(arr[0]);
	arr = new int[size];
	ifs.read((char*)arr, fileSize);
}
