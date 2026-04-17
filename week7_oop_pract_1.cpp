#include <iostream>
#include "Greyscale.h"
#include "Inverted.h"

int main()
{
    Image img = readImage("bird.ppm");

    Greyscale g;
    g.convertToGrey(img);

    Inverted inv;
    inv.Invert(img);

    return 0;
}

