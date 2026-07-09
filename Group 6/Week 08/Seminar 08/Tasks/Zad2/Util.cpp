#include "Util.h"

bool Util::charIsNumber(char ch)
{
    int num = ch - '0';
    if (num>=0&&num<=9)
    {
        return true;
    }
    return false;
}

bool Util::charIsLetter(char ch)
{
    if (ch>='a'&&ch<='z')
    {
        return true;
    }
    if (ch>='A'&&ch<='Z')
    {
        return true;
    }
    return false;
}

bool Util::checkNCharsIfTheyAreNumbers(const char* _chars, int n, int startIndex)
{
    for (size_t i = startIndex; i < n; i++)
    {
        if (!charIsNumber(_chars[i]))
        {
            return false;
        }
    }
    return true;
}
