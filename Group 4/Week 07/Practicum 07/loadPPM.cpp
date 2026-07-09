#include "loadPPM.h"

Image loadPPM::  function_loadPPM(const char *filename) {
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Cannot open file: " << filename << "\n";
        return Image();
    }

    std::string format;
    file >> format;

    if (format != "P6") {
        std::cout << "Unsupported PPM format: " << format << "\n";
        return Image();
    }

    size_t width, height, maxVal;
    file >> width >> height >> maxVal;
    file.get();

    size_t byteCount = width * height * 3;
    unsigned char* data = new unsigned char[byteCount];

    file.read(reinterpret_cast<char*>(data), byteCount);

    if (!file) {
        std::cout << "Error while reading pixel data\n";
        delete[] data;
        return Image();
    }

    Image img(width, height, maxVal, data);
    delete[] data;
    return img;
}