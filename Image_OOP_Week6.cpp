#include <iostream>
#include "Image.h"
#include "Inverted.h"
#include "Greyscale.h"
#include "ImageUtils.h"


int main()
{
    std::ifstream is("cat.ppm", std::ios::binary);

    Image img(is);

    Inverted inv;
    Image inverted = inv.convertToInverted(img);
    ImageUtils::savePPM(inverted);

    Greyscale gs;
    gs.convertToGrey(img);

    return 0;
}
