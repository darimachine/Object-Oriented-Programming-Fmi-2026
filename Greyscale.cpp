#include "Greyscale.h"
#include <fstream>
#include <iostream>

void Greyscale::convertToGrey(const Image& image)
{
	std::ofstream of("greyImage.pgm", std::ios::binary);

	if (!of.is_open())
	{
		std::cout << "Error opening file!\n";
		return;
	}

	of << "P5\n" << image.getWidth() << " " << image.getHeight() << "\n" << maxval<<"\n";

	int size = image.getWidth() * image.getHeight() * 3;

	for (int i = 0; i < size; i+=3)
	{
		double grey = 0.299 * image[i] + 0.587 * image[i + 1] + 0.114 * image[i + 2];
		unsigned char greyChar = (unsigned char)(grey);
		of.put(greyChar);
	}
}
