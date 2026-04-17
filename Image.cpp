#include "Image.h"
#include <iostream>
#include <fstream>

void Image::copyFrom(const Image& other)
{
	width = other.width;
	height = other.height;

	int size = width * height * 3;

	bytes = new unsigned char[size];

	for (int i = 0; i < size; i++)
	{
		bytes[i] = other.bytes[i];
	}
}

void Image::free()
{
	delete[] bytes;
	bytes = nullptr;
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

Image::Image():width(0), height(0), bytes(nullptr)
{
}

Image::Image(int width, int height, const unsigned char* bytes): width(width), height(height)
{
	int size = width * height * 3;
	this->bytes = new unsigned char[size];

	for (int i = 0; i < size; i++)
	{
		this->bytes[i] = bytes[i];
	}
}

Image::Image(const Image& other)
{
	copyFrom(other);
}

Image& Image::operator=(const Image& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Image::~Image()
{
	free();
}

Image::Image(Image&& other) noexcept
{
	moveFrom(std::move(other));
}

Image& Image::operator=(Image&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

int Image::getWidth() const
{
	return width;
}

int Image::getHeight() const
{
	return height;
}

const unsigned char& Image::operator[](int index) const
{
	return bytes[index];
}

Image readImage(const char* filename)
{
	std::ifstream is(filename, std::ios::binary);

	char magic[3];
	int width, height, maxval;

	is >> magic >> width >> height >> maxval;
	is.ignore(1); 

	int size = width * height * 3;
	unsigned char* data = new unsigned char[size];

	is.read((char*)data, size);

	Image img(width, height, data);

	delete[] data;

	return img;
}
