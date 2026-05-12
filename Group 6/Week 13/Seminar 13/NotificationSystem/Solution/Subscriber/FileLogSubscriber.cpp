#include "FileLogSubscriber.h"

FileLogSubscriber::FileLogSubscriber(const string& fileName)
{
	file = ofstream(fileName, std::ios::app);
}

void FileLogSubscriber::onEvent(const string& eventType, const string& message)
{
	if (!file.is_open()) return;
	file << '[' << eventType << "] " << message << endl;
}
