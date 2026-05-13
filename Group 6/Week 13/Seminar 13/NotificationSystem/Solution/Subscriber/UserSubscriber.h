#pragma once
#include "ISubscriber.h"
#include "Recipient.h"
#include <vector>
class UserSubscriber : public ISubscriber
{
	Recipient recipient;
	vector<string> eventTypes;
	string notificationSenderName;

	bool isInterestedIn(const string& eventType) const;
public:
	UserSubscriber(const Recipient& recipient, const vector<string>& eventTypes, const string& sn);
	void onEvent(const string& eventType, const string& message) override;
};

