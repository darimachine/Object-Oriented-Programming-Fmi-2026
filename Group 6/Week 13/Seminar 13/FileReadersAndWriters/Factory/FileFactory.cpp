#include "FileFactory.h"
#include "FilePath.h"
#include "BinaryFileReader.h"
#include "ArrFileReader.h"
#include "CsvFileReader.h"

#include "BinaryFileWriter.h"
#include "ArrFileWriter.h"
#include "CsvFileWriter.h"
FileReader* FileFactory::fileReadFactory(const MyString& fileName)
{
    FilePath path(fileName);
    if (path.getExtension() == ".dat") {
        return new BinaryFileReader(fileName);
    }
    if (path.getExtension() == ".arr") {
        return new ArrFileReader(fileName);
    }
    if (path.getExtension() == ".csv") {
        return new CsvFileReader(fileName);
    }
    throw std::exception("invalid fileName");
}

FileWriter* FileFactory::fileWriterFactory(const MyString& fileName)
{
    FilePath path(fileName);
    if (path.getExtension() == ".dat") {
        return new BinaryFileWriter(fileName);
    }
    if (path.getExtension() == ".arr") {
        return new ArrFileWriter(fileName);
    }
    if (path.getExtension() == ".csv") {
        return new CsvFileWriter(fileName);
    }
    return new ArrFileWriter(fileName);
}
