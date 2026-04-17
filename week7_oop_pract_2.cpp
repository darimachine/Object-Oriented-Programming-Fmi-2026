#include <iostream>
#include "Gallery.h"

int main()
{
    Image img1 = readImage("bird.ppm");

    Gallery g;

    g.add(&img1);

    std::cout << "Empty slots: ";
    g.showEmpty();

    Image* first = g[0];
    if (first)
        std::cout << "First image width: " << first->getWidth() << "\n";

    Gallery ppmOnly = g.filter(ImageType::PPM);
    std::cout << "PPM count: " << ppmOnly.getSize() << "\n"; 

    Image* largest = g.findLargest();
    if (largest)
        std::cout << "Largest: " << largest->getWidth() * largest->getHeight() << " pixels\n";

    g.remove(0);
    std::cout << "After remove, size: " << g.getSize() << "\n"; 
   

    return 0;
}
