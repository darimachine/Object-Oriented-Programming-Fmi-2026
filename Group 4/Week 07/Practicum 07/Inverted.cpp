#include "Inverted.h"

Image Inverted::convertToInverted(const Image &image) {
    Image result= image;

    size_t maxVal=result.getMaxVal();
    size_t byteCount= result.getByteCount();
     unsigned char* bytes = result.getBytes();

    for (int i=0; i < byteCount/3; i++) {
        size_t idx=i*3;
        int r = bytes[idx];
        int g = bytes[idx+1];
        int b = bytes[idx+2];

        bytes[idx] = maxVal-r;
        bytes[idx+1] = maxVal-g;
        bytes[idx+2] = maxVal-b;
    }
    return result;

}