#include "Image.h"

int Image::maxval = 255;

Image::Image() :width(0), height(0)
{
	bytes = new unsigned char[1];
	bytes[0] = '\0';
}

Image::Image(int width, int height) :width(width), height(height)
{
	int size = width * height * 3;
	bytes = new unsigned char[size];
}

Image::Image(std::istream& is)
{
	char magicBuffer[3];
	int width, height, maxval;

	is >> magicBuffer >> width >> height >> maxval;
	is.ignore(1);

	this->width = width;
	this->height = height;
	Image::maxval = maxval;

	int size = width * height * 3;
	bytes = new unsigned char[size];
	is.read((char*)bytes, size);
}

void Image::copyFrom(const Image& other)
{
	width = other.width;
	height = other.height;

	int size = width * height * 3;
	unsigned char* newBytes = new unsigned char[size];
	for (int i = 0;i < size;i++)
	{
		newBytes[i] = other.bytes[i];
	}

	delete[]bytes;
	bytes = newBytes;
}

void Image::moveFrom(Image&& other)
{
	width = other.width;
	height = other.height;

	bytes = other.bytes;
	other.bytes = nullptr;
	other.width = 0;
	other.height = 0;
}

void Image::free()
{
	delete[]bytes;
	bytes = nullptr;
	width = 0;
	height = 0;
}

Image::~Image()
{
	free();
}

Image::Image(const Image& other)
{
	copyFrom(other);
}

Image& Image::operator=(const Image& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Image::Image(Image&& other)noexcept
{
	moveFrom(std::move(other));
}

Image& Image::operator=(Image&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

int Image::getWidth()const
{
	return width;
}

int Image::getHeight()const
{
	return height;
}

const ImageType Image::getType()const
{
	return type;
}

int Image::getMaxval()
{
	return maxval;
}

const unsigned char& Image::operator[](int index)const
{
	return bytes[index];
}

unsigned char& Image::operator[](int index)
{
	return bytes[index];
}

void printImageInfo(const Image* image)
{
	std::println("Image: {}x{}", image->getWidth(), image->getHeight());
}