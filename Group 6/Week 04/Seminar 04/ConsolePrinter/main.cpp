#include <iostream>
#include "ConsolePrinter.h"
#include "StringWrapper.h"
#include "NumberWrapper.h"

int main()
{
    auto removeVowels = [](char ch) {
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
    auto removeDigits = [](char ch) {
        return ch >= '0' && ch <= '9';
        };

    ConsolePrinter vowelPrinter(removeVowels);
    ConsolePrinter digitPrinter(removeDigits);

    StringWrapper word1("Apple123", vowelPrinter);
    StringWrapper word2("Banana456", vowelPrinter);

    cout << "word1: "; word1.println(); 
    cout << "word2: "; word2.println(); 

    cout << "Резултат след смяната:" << endl;
    word1.setConsolePrinter(digitPrinter);
    cout << "word1: "; word1.println(); 

    cout << "word2: "; word2.println();

    // Създаваме принтер, който филтрира И гласни, И цифри!
    Predicate noVowelsOrDigits = Predicates::combineOr(removeVowels, removeDigits);
    ConsolePrinter ultraPrinter(noVowelsOrDigits);

    StringWrapper password("MySecretPass123", ultraPrinter);
    cout << "Строга цензура: ";
    password.println(); // Очакваме: M*S*cr*tP*ss***

}