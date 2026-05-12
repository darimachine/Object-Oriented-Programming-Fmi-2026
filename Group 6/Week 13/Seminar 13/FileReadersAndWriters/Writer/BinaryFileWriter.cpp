#include "BinaryFileWriter.h"

BinaryFileWriter::BinaryFileWriter(const MyString& fileName) : FileWriter(fileName)
{
}

void BinaryFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(fileName.c_str(),std::ios::binary);
	if (!ofs.is_open()) {
		return;
	}
	ofs.write((const char*)arr, sizeof(arr[0]) * size);
}
