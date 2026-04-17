#include "Inverted.h"
#include <iostream>
#include <fstream>

void Inverted::Invert(const Image& image)
{
	std::ofstream of("invertedImage.ppm", std::ios::binary);

	if (!of.is_open())
	{
		std::cout << "Error opening file!\n";
		return;
	}

	of << "P6\n" << image.getWidth() << " " << image.getHeight() << "\n" << maxval << "\n";

	int size = image.getWidth() * image.getHeight() * 3;

	for (int i = 0; i < size; i++)
	{
		char inverted = maxval - image[i];
		of.put(inverted);
	}
}
