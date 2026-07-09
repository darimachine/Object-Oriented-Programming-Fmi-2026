//
// Created by Boris Bozhilov on 4/10/2026.
//

#include <iostream>
#include <fstream>
#include "GrayscaleImage.h"

GrayscaleImage::GrayscaleImage() = default;
GrayscaleImage::GrayscaleImage(const GrayscaleImage& other) = default;
GrayscaleImage& GrayscaleImage::operator=(const GrayscaleImage& other) = default;
GrayscaleImage::GrayscaleImage(GrayscaleImage&& other) noexcept = default;
GrayscaleImage& GrayscaleImage::operator=(GrayscaleImage&& other) noexcept = default;

GrayscaleImage::GrayscaleImage(const char *fileName) : Image(fileName){

    // setting the type of the image to match the PGM format
    pType = 5;

    // making the image greyscale
    const int dataSize = getSizeOfData(COUNT_OF_CHANNELS_PGM);

    for (int i = 0; i < dataSize; i++) {

        const int srcPixelIndex = i * 3;

        data[i] = 0.299 * data[srcPixelIndex]
                  + 0.587 * data[srcPixelIndex + 1]
                  + 0.114 * data[srcPixelIndex + 2];
    }
}

GrayscaleImage::~GrayscaleImage() {

    delete[] data;
    setToInvalidState();
}


