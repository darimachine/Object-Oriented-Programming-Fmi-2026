#include "Greyscale.h"

void Greyscale::convertToGrey(const Image& image)
{
	std::ofstream file("greyscaleImage.pgm", std::ios::binary);
	if (!file.is_open())
	{
		return;
	}
	file << "P5\n" << image.getWidth() << " " << image.getHeight() 
		<< '\n' << image.getMaxval() << '\n';

	int size = image.getWidth() * image.getHeight() * 3;
	for (int i = 0;i < size;i+=3)
	{
		double grey = 0.299 * image[i] + 0.587 * image[i + 1] + 0.114 * image[i + 2];
		file.put(grey);
	}
	file.close();
}