#pragma once
#include<iostream>
#include<fstream>
#include"ImageType.h"
#include<print>

class Image
{
private:
	unsigned char* bytes = nullptr;
	int width = 0;
	int height = 0;
	ImageType type = ImageType::PPM;
	static int maxval;

	void copyFrom(const Image& other);
	void free();
	void moveFrom(Image&& other);

public:
	Image();
	Image(int width, int height);
	Image(std::istream& is);
	~Image();

	Image(const Image& other);
	Image(Image&& other) noexcept;
	Image& operator=(const Image& other);
	Image& operator=(Image&& other) noexcept;

	int getWidth()const;
	int getHeight()const;
	const ImageType getType()const;
	static int getMaxval();

	const unsigned char& operator[](int index)const;
	unsigned char& operator[](int index);
};

void printImageInfo(const Image* image);