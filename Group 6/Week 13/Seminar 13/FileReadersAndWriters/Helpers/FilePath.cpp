#include "FilePath.h"

FilePath::FilePath(const MyString& fileName)
{
	int i = fileName.length() - 1;
	for (; i>=0;i--)
	{
		if (fileName[i] == '.') {
			break;
		}
	}
	this->fileName = fileName.substr(0, i);
	this->extension = fileName.substr(i, fileName.length() - i);

}

const MyString& FilePath::getFileName() const
{
	return fileName;
}

const MyString& FilePath::getExtension() const
{
	return extension;
}
