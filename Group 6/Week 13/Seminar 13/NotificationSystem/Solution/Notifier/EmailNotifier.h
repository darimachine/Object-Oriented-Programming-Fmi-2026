#pragma once
#include "Notifier.h"
class EmailNotifier : public Notifier
{
public:
	EmailNotifier(const string& senderName);

	void send(const Recipient& recipient, const string& message) const override;
};

