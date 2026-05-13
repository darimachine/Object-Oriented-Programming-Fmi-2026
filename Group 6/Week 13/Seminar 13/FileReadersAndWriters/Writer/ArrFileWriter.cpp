#include "ArrFileWriter.h"

ArrFileWriter::ArrFileWriter(const MyString& fileName) : FileWriter(fileName)
{
}

void ArrFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open()) {
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) {
			ofs << arr[i];
		}
		else {
			ofs << arr[i] << " ";
		}
		
	}
}
