#include "Inverted.h"

const Image Inverted::convertToInverted(const Image& image)const
{
	Image inverted(image.getWidth(), image.getHeight());

	int size = image.getWidth() * image.getHeight() * 3;
	for (int i = 0;i < size;i++)
	{
		inverted[i] = image.getMaxval() - image[i];
	}

	return inverted;
}