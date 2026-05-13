#pragma once
#include "ISubscriber.h"
#include <fstream>
class FileLogSubscriber : public ISubscriber 
{
	ofstream file;

public:
	FileLogSubscriber(const string& fileName);


	// Inherited via ISubscriber
	void onEvent(const string& eventType, const string& message) override;

};

