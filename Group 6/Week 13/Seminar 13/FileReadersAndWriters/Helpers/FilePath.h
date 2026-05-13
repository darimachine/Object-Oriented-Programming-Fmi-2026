#pragma once
#include "MyString.h"
class FilePath
{
	MyString fileName;
	MyString extension;

public:
	FilePath(const MyString& fileName);

	const MyString& getFileName() const;
	const MyString& getExtension() const;
};

