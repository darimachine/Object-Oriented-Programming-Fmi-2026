//
// Created by Boris Bozhilov on 4/19/2026.
//

#include "Utility.h"

#include <cstring>

bool Utility::isLetter(const char c) {

    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Utility::isDigit(const char c) {

    return c >= '0' && c <= '9';
}

void Utility::copyStringData(const char *source, char*& destination) {

    if (source == nullptr) return;
    if (source == destination) return;

    delete[] destination;

    const unsigned int sourceLength = strlen(source);

    destination = new char[sourceLength + 1];
    strncpy(destination, source, sourceLength);
    destination[sourceLength] = '\0';
}

void Utility::moveStringData(char*& source, char*& destination) {

    if (source == destination) return;

    delete[] destination;
    destination = source;
    source = nullptr;
}
