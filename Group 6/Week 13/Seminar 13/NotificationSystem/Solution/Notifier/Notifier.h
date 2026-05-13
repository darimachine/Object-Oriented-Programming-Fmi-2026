#pragma once
#include <iostream>
#include "Recipient.h"
using namespace std;
class Notifier
{
protected:
	string senderName;

public:
	explicit Notifier(const string& senderName);

	virtual void send(const Recipient& recipient, const string& message) const = 0;
	virtual ~Notifier() = default;
};

