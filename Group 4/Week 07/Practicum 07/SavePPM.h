#pragma once
#include <fstream>
#include <iostream>
#include "Image.h"

class SavePPM {
    public:
    static void function_savePPM( Image& img, const char* filename, size_t width, size_t height);
};