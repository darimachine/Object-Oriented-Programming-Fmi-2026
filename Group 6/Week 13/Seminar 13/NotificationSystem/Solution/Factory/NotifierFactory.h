#pragma once
#include "Notifier.h"
class NotifierFactory
{
public:
	static unique_ptr<Notifier> create(const string& address, const string& senderName);
};

