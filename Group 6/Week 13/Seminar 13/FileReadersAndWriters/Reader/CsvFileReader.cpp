#include "CsvFileReader.h"
#include "StreamHelper.h"
CsvFileReader::CsvFileReader(const MyString& fileName) : FileReader(fileName)
{

}

void CsvFileReader::read(int*& arr, size_t& size) const
{
	std::ifstream ifs(fileName.c_str());

	if (!ifs.is_open()) {
		throw std::exception("Couldnt open");
	}
	delete[] arr;
	size = StreamHelper::getCharCount(ifs, ',') + 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ifs >> arr[i];
		ifs.ignore();
		// >> preskachat novi redove i intervali i tabulacii
	}
}
