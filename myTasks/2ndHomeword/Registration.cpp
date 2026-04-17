#include  <iostream>
#include "Registration.h"
#include  <print>

constexpr  int REGS_PLACE_ONE_SYMB = 7;
constexpr  int REGS_PLACE_TWO_SYMB = 8;

bool Registration::isDigit(char symb) const
{
    return symb >= '0' && symb <='9';
}

bool Registration::isLetter(char symb) const
{
    return  symb >='A' && symb<='Z';
}

Registration::Registration(const char *inpStr)
{
    size_t len = inpStr !=nullptr ? strlen(inpStr) : 0;
    if (inpStr == nullptr || len > REGS_PLACE_TWO_SYMB || len < REGS_PLACE_ONE_SYMB)
    {
        return;
    }

    int placeLen = 0;
    if (isLetter(inpStr[0]) && isDigit(inpStr[1]))
    {
        placeLen = 1;
    }
    else if (isLetter(inpStr[0]) && isLetter(inpStr[1]) && isDigit(inpStr[2]))
    {
        placeLen = 2;
    }
    else
    {
        return;
    }

    if (placeLen == 1)
    {
        for (int i =1; i < 5; i++)
        {
            if (!isDigit(inpStr[i]))
            {
                return;
            }
        }
    }
    else
    {
        for (int i =2; i < 6; i++)
        {
            if (!isDigit(inpStr[i]))
            {
                return;
            }
        }
    }
    if (!isLetter(inpStr[len -1]) || !isLetter(inpStr[len -2]))
    {
        return;
    }

    strcpy(registrationNum, inpStr);
    std::println("The registration number is valid");
}

const char *Registration::getRegNumb() const
{
    return registrationNum;
}

std::ostream& operator<<(std::ostream& os, const Registration& obj)
{
    os<<"The registration number is: "<<obj.getRegNumb();
    return  os;
}

bool operator==(const Registration& rhs, const Registration& lhs)
{
    return strcmp(rhs.registrationNum, lhs.registrationNum) == 0;
}
std::strong_ordering Registration::operator<=>(const Registration& other) const
{
   int result = strcmp(registrationNum, other.registrationNum);

    return  result <=> 0;

}

void Registration::setRegNum(const char *str)
{
    if (!str || strlen(str) > REG_NUM_MAX_LEN)
    {
        return;
    }
    strcpy(registrationNum, str);
}

int main()
{
    const char* reg = "CB1234MK";
    Registration first(reg);

    std::cout<<first<<'\n';

    return 0;
}