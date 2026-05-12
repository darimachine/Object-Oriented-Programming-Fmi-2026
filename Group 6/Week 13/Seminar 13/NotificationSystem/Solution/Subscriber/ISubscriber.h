#pragma once
#include <iostream>
using namespace std;
class ISubscriber
{
public:
	virtual void onEvent(const string& eventType, const string& message) = 0;
	virtual ~ISubscriber() = default;
};

