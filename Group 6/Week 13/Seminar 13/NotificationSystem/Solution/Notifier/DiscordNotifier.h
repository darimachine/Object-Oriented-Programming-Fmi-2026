#pragma once
#include <iostream>
#include "Notifier.h"
class DiscordNotifier : public Notifier
{
public:
	DiscordNotifier(const string& senderName);

	void send(const Recipient& recipient, const string& message) const override;
};

