#include <iostream>

class BankAccount {
private:
    double balance;
    mutable int inquiryCount;  // we need this counter to be updated in all balance checks, which are const methods, and we can do that with the `mutable` keyword
    int transactionCount; // this will only be updated in non-const methods
    mutable int allOperationsCount; // this will be updated in all methods

public:
    BankAccount() : BankAccount(0.0) {}

    explicit BankAccount(double initialBalance) : balance(initialBalance), inquiryCount(0), transactionCount(0), allOperationsCount(0) {}

    // Const method to check balance
    double getBalance() const {
        ++inquiryCount; // Allowed because inquiryCount is mutable
        ++allOperationsCount; // Allowed because allOperationsCount is mutable
        std::cout << "[BALANCE CHECK] Inquiry count: " << inquiryCount << std::endl;
        return balance;
    }

    // Non-const method to deposit money
    void deposit(double amount) {
        ++allOperationsCount;
        if (amount > 0) {
            balance += amount;
            ++transactionCount;
            std::cout << "[DEPOSIT] Amount: $" << amount << " | Total Transactions: " << transactionCount << std::endl;
        }
    }

    // Non-const method to withdraw money
    void withdraw(double amount) {
        ++allOperationsCount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            ++transactionCount;
            std::cout << "[WITHDRAW] Amount: $" << amount << " | Total Transactions: " << transactionCount << std::endl;
        } else {
            std::cout << "[WITHDRAW] Insufficient funds!" << std::endl;
        }
    }

    // Display statistics
    void showStats() const {
        ++allOperationsCount; // Allowed because allOperationsCount is mutable
        std::cout << "All Operations: " << allOperationsCount << std::endl;
        std::cout << "Total Inquiries: " << inquiryCount << " | Total Transactions: " << transactionCount << std::endl;
    }
};

int main() {
    BankAccount account(1000.0);

    // Checking balance multiple times (const method)
    std::cout << "Current Balance: $" << account.getBalance() << std::endl;
    std::cout << "Current Balance: $" << account.getBalance() << std::endl;

    // Performing transactions
    account.deposit(500);
    account.withdraw(300);
    account.withdraw(1500);

    // More balance checks
    std::cout << "Current Balance: $" << account.getBalance() << std::endl;

    // Display statistics
    account.showStats();

    return 0;
}
