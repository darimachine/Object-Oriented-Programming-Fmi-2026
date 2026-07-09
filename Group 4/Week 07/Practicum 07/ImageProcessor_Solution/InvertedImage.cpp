//
// Created by Boris Bozhilov on 4/10/2026.
//

#include <iostream>
#include <fstream>
#include "InvertedImage.h"

InvertedImage::InvertedImage() = default;
InvertedImage::InvertedImage(const InvertedImage& other) = default;
InvertedImage& InvertedImage::operator=(const InvertedImage& other) = default;
InvertedImage::InvertedImage(InvertedImage&& other) noexcept = default;
InvertedImage& InvertedImage::operator=(InvertedImage&& other) noexcept = default;

InvertedImage::InvertedImage(const char *fileName) : Image(fileName){

    // setting the type of the image to match the PGM format
    pType = 6;

    //inverting the image
    const int dataSize = getSizeOfData(COUNT_OF_CHANNELS_PPM);

    for (int i = 0; i < dataSize; i++) {

        data[i] = maxVal - data[i];
    }
}

InvertedImage::~InvertedImage() {

    delete[] data;
    this->setToInvalidState();
}




