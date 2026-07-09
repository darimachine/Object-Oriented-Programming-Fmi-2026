#include <iostream>

#include "GrayscaleImage.h"
#include "Image.h"
#include "InvertedImage.h"

int main() {

    InvertedImage inverted_image = InvertedImage("bird.ppm");
    GrayscaleImage grayscale_image = GrayscaleImage("bird.ppm");

    inverted_image.createImage("InvertedBird.ppm");
    grayscale_image.createImage("GrayscaleBird.pgm");

    return 0;
}
