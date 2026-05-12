#include "NotifierFactory.h"
#include "SMSNotifier.h"
#include "DiscordNotifier.h"
#include "EmailNotifier.h"


static bool startsWith(const string& address, const string& prefix) {
    return address.find(prefix) == 0;
}
static bool isAllDigits(const string& address) {

    if (address.empty()) return false;

    for (const auto& c : address) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}
static bool looksLikeEmail(const string& address) {
    size_t atPos = address.find('@');
    if (atPos == string::npos) {
        return false;
    }

    return address.find('.', atPos) != string::npos;
}
unique_ptr<Notifier> NotifierFactory::create(const string& address, const string& senderName)
{
    if (startsWith(address,"+") || isAllDigits(address)) {
        return make_unique<SMSNotifier>(senderName);
    }
    if (startsWith(address, "@") || startsWith(address,"#")) {
        return make_unique<DiscordNotifier>(senderName);
    }
    if (looksLikeEmail(address)) {
        return make_unique<EmailNotifier>(senderName);
    }


   throw invalid_argument("Invalid address");
}
