#include <iostream>

#include "Image.h"

int main() {

    Image birdImage("bird.ppm");

    birdImage.createImage("birdProcessed.ppm");
    birdImage.createInvertedImage("birdInverted.ppm");
    birdImage.createGrayscaleImage("birdGrayscale.pgm");

    return 0;
}
