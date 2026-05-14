
#include <iostream>
#include "MyString.h"
#include "FileFactory.h" // it includes FileReader and FileWriter only!!! in the cpp are the other includes!!
void transfer(const MyString& fromRead, const MyString& toSave) {
	FileReader* reader = FileFactory::fileReadFactory(fromRead);
	FileWriter* writer = FileFactory::fileWriterFactory(toSave);

	int* arr = nullptr;
	size_t size = 0;
	reader->read(arr, size);
	//can do some logic for the arr before saving
	writer->write(arr, size);

	delete[] arr;
	delete reader;
	delete writer;

}
int main()
{
	transfer("numbers.dat", "myNumbers1.oop");
}
