#pragma once
#include "ISubscriber.h"
#include <vector>
class Eventy
{
	vector <shared_ptr<ISubscriber>> subscribers;
public:
	void subscribe(const shared_ptr<ISubscriber>& sub);
	void unsubscribe(const shared_ptr<ISubscriber>& sub);
	void publish(const string& eventType, const string& message) const;
};

