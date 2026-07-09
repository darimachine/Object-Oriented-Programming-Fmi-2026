#include "Registration.h"
#include "Util.h"
bool Registration::validateNumber(const char* _number) const
{
    bool res = false;
    int len = strlen(_number);
    if (len!=8&& len != 7)
    {
        return false;
    }


    int ind = 0;
    if (len==8)// ab1234cd
    {
        if (!Util::charIsLetter(_number[ind++]))
        {
            return false;
        }
    }

    //a1234cd
    if (!Util::charIsLetter(_number[ind++]))
    {
        return false;
    }
        
    res = Util::checkNCharsIfTheyAreNumbers(_number,4, ind);
    if (res==false)
    {
        return false;
    }
    ind += 4;
    if (!Util::charIsLetter(_number[ind++]))
    {
        return false;
    }
    if (!Util::charIsLetter(_number[ind++]))
    {
        return false;
    }

    
    return true;
}

Registration::Registration(const char* _number)
{
    if (!validateNumber(_number))
    {
        std::cout << "Invalid number( "<<_number<<" ). Putting empty string for the number as a way to show error (shrug)\n";
        return;
    }
    strcpy_s(number, _number);
}

char* Registration::getNumber()
{
    return number;
}

bool Registration::operator==(Registration& other)
{
    return strcmp(number,other.getNumber())==0;
}
std::strong_ordering Registration::operator<=>(Registration& other)
{
    if (this->getNumber()==other.getNumber())
    {
        return std::strong_ordering::equal;
    }
    if (strcmp(this->getNumber(), other.getNumber())<0)
    {
        return std::strong_ordering::less;
    }
    if (strcmp(this->getNumber(), other.getNumber())>0)
    {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering();
}

std::ostream& operator<<(std::ostream& os, Registration& s)
{
    os << s.getNumber();
    return os;
}

