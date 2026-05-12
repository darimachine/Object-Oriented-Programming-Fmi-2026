#pragma once
#include "Notifier.h"
class SMSNotifier : public Notifier
{
public:
	SMSNotifier(const string& senderName);
	void send(const Recipient& recipient, const string& message) const override;
};

