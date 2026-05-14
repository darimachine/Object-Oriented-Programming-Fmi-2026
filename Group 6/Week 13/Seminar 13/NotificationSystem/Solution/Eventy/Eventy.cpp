#include "Eventy.h"

void Eventy::subscribe(const shared_ptr<ISubscriber>& sub)
{
	subscribers.push_back(sub);
}

void Eventy::unsubscribe(const shared_ptr<ISubscriber>& sub)
{
	erase_if(subscribers, [&](const shared_ptr<ISubscriber>& s) {
		return s == sub; 
		});
}

void Eventy::publish(const string& eventType, const string& message) const
{
	for (const auto& sub : subscribers) {
		sub->onEvent(eventType, message);
	}
	cout << endl;
}
