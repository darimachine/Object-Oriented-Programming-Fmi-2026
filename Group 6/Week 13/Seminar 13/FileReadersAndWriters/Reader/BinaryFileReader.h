#pragma once
#include "FileReader.h"
class BinaryFileReader : public FileReader
{
public:
	BinaryFileReader(const MyString& fileName);
	// Inherited via FileReader
	void read(int*& arr, size_t& size) const override;
};

