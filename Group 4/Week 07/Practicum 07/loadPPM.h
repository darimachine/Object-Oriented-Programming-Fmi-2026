#pragma once
#include <fstream>
#include <iostream>
#include "Image.h"
class loadPPM {
    public:
    static Image function_loadPPM(const char * filename);
};