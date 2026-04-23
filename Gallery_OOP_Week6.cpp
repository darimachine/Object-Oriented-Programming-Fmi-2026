#include <iostream>
#include "Gallery.h"

int main()
{
    Gallery g;

    std::ifstream is1("cat.ppm", std::ios::binary);
    std::ifstream is2("input.ppm", std::ios::binary);

    if (!is1.is_open() || !is2.is_open())
    {
        std::cout << "Cannot open input files!\n";
        return 1;
    }

    Image* img1 = new Image(is1);
    Image* img2 = new Image(is2);

    is1.close();
    is2.close();

    g.add(img1);
    g.add(img2);

    g.showEmpty();

    Gallery filtered = g.filter(ImageType::PPM);

    const Image* largest = g.findLargest();
    if (largest)
    {
        std::cout << "Found largest image!\n";
    }

    g.applyToAll(printImageInfo);

    g.saveAll("output");

    Gallery g2;
    g2.add(new Image(*img1));

    Gallery g3 = g + g2;

    g.clear();
    filtered.clear();
    g2.clear();
    g3.clear();

    return 0;
}