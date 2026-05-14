#include "UserSubscriber.h"
#include "NotifierFactory.h"

bool UserSubscriber::isInterestedIn(const string& eventType) const
{
	for (const auto& el : eventTypes) {
		if (el == eventType) {
			return true;
		}
	}
	return false;
}

UserSubscriber::UserSubscriber(const Recipient& recipient, const vector<string>& eventTypes,
	const string& sn) : recipient(recipient), eventTypes(eventTypes), notificationSenderName(sn)
{
}

void UserSubscriber::onEvent(const string& eventType, const string& message)
{
	if (!isInterestedIn(eventType)) return;

	try {
		auto notifier = NotifierFactory::create(recipient.getAddress(), notificationSenderName);
		notifier->send(recipient, message);
	}
	catch (const invalid_argument& e) {
		cout << e.what();
	}
}
