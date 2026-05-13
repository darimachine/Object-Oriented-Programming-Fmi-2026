#pragma once
#include "FileWriter.h"
class CsvFileWriter : public FileWriter
{
public:
	CsvFileWriter(const MyString& fileName);


	// Inherited via FileWriter
	void write(const int* arr, size_t size) const override;

};

