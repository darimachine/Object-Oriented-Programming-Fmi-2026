#include "EmailNotifier.h"
#include <print>
EmailNotifier::EmailNotifier(const string& senderName) : Notifier(senderName)
{
}

void EmailNotifier::send(const Recipient& recipient, const string& message) const
{
	println("[EMAIL from {}]\nTo: {} ({})\nSubject: Notification\nBody: {}",
		senderName,
		recipient.getAddress(),
		recipient.getName(),
		message);
}
