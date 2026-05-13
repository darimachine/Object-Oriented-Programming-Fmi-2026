#include "SMSNotifier.h"
#include <print>
SMSNotifier::SMSNotifier(const string& senderName): Notifier(senderName)
{

}

void SMSNotifier::send(const Recipient& recipient, const string& message) const
{
	println("[SMS from {}] To {} ({}): {}", 
		senderName, 
		recipient.getAddress(), 
		recipient.getName(), 
		message);
}
