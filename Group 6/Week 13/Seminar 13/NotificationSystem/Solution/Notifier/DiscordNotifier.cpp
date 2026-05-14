#include "DiscordNotifier.h"
#include <print>
DiscordNotifier::DiscordNotifier(const string& senderName) : Notifier(senderName)
{
}

void DiscordNotifier::send(const Recipient& recipient, const string& message) const
{
	println("[DISCORD from {}] {}: **{}**",
		senderName,
		recipient.getAddress(),
		message);
}
