#pragma once
#include "FileReader.h"
class CsvFileReader : public FileReader
{

public:
	CsvFileReader(const MyString& fileName);
	void read(int*& arr, size_t& size) const override;
};

