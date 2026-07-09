#include "ImageG.h"
#include <iostream>
#include <fstream>

void Image::copyFrom(const Image& other)
{
	width = other.width;
	height = other.height;
	type = other.getType();

	int size = (type == ImageType::PPM) ? width * height * 3 : width * height;

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
	type = other.type;
	bytes = other.bytes;

	other.bytes = nullptr;
	other.width = 0;
	other.height = 0;
	other.type = ImageType::UNKNOWN;
}

Image::Image() :width(0), height(0), bytes(nullptr), type(ImageType::UNKNOWN)
{
}

Image::Image(int width, int height, ImageType type, const unsigned char* bytes) : width(width), height(height), type(type)
{
	int channels = (type == ImageType::PPM) ? 3 : 1;
	int size = width * height * channels;
	
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

ImageType Image::getType() const
{
	return type;
}

void Image::saveImage(const char* fileName)
{
	std::ofstream ofs(fileName, std::ios::binary);

	if (!ofs.is_open())
	{
		std::cout << "Error opening file!\n";
		return;
	}

	const char* typeStr = nullptr;
	size_t size = 0;

	if (type == ImageType::PGM) {
		typeStr = "P5";
		size = width * height;
	}
	else if (type == ImageType::PPM) {
		typeStr = "P6";
		size = width * height*3;
	}

	ofs << typeStr << "\n";
	ofs << width << " " << height << "\n";
	ofs << maxval << "\n";

	ofs.write((const char*)bytes, size);

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

	ImageType type;

	if (strcmp(magic, "P6") == 0) {
		type = ImageType::PPM;
	}
		
	else if (strcmp(magic, "P5") == 0) {
		type = ImageType::PGM;
	}
		
	else {
		type = ImageType::UNKNOWN;
	}

	is.read((char*)data, size);

	Image img(width, height, type, data);

	delete[] data;

	return img;
}
