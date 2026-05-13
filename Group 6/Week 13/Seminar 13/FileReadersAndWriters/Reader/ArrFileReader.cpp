#include "ArrFileReader.h"
#include "StreamHelper.h"
ArrFileReader::ArrFileReader(const MyString& fileName) : FileReader(fileName)
{
}

void ArrFileReader::read(int*& arr, size_t& size) const
{
	std::ifstream ifs(fileName.c_str());

	if (!ifs.is_open()) {
		throw std::exception("Could open");
	}
	delete[] arr;
	size = StreamHelper::getCharCount(ifs, ' ') + 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ifs >> arr[i];
		// >> preskachat novi redove i intervali i tabulaci
	}
}
