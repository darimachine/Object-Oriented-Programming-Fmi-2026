#include "Utils.h"
#include <cstring>

bool Utils::isDigit(char ch)
{
    return ch>='0' && ch<='9';
}

bool Utils::isUpper(char ch)
{
    return ch>='A'&& ch<='Z';
}

char* Utils::copyDynamicString(const char* src)
{
    if (!src) {
        char* result = new char[1];
        result[0] = '\0';
        return result;
    }

    size_t size = strlen(src) + 1;
    char* result = new char[size];
    strcpy_s(result, size, src);
    return result;
}
