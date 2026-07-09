#include "Greyscale.h"
#include "Image.h"

Image Greyscale::convertToGrey(const Image &image) {
    const double convertRed=0.299;
    const double convertGreen=0.587;
    const double convertBlue=0.114;
    Image copyImage = image;
    size_t byteSize = copyImage.getByteCount()/3;
    unsigned char *byteArray = copyImage.getBytes();
    for (int i=0; i<byteSize; i++ ) {
       size_t idx=i*3;
        int r = byteArray[idx];
        int g = byteArray[idx+1];
        int b = byteArray[idx+2];

        unsigned char grey= static_cast<unsigned char>(r*convertRed+g*convertGreen+b*convertBlue);
        byteArray[idx] = grey;
        byteArray[idx+1] = grey;
        byteArray[idx+2] = grey;
    }

    return copyImage;
}