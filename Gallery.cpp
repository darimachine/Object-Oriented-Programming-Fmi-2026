#include "Gallery.h"
#include <iostream>
#include <fstream>
#include <print>

void Gallery::copyFrom(const Gallery& other)
{
	size = other.size;
	capacity = other.capacity;

	gallery = new Image* [capacity];

	if (size > capacity) {
		return;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (other.gallery[i]) {
			gallery[i] = new Image(*other.gallery[i]);
		}
		else {
			gallery[i] = nullptr;
		}
			
	}
}

void Gallery::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete gallery[i];
	}

	delete[] gallery;
	gallery = nullptr;
}

void Gallery::moveFrom(Gallery&& other)
{
	size = other.size;
	capacity = other.capacity;
	gallery = other.gallery;

	other.gallery = nullptr;
	other.size = 0;
	other.capacity = INITIAL_CAP;
}

void Gallery::resize(size_t newCap)
{
	Image** resized = new Image * [newCap] {nullptr};

	for (int i = 0; i < capacity; i++)
	{
		resized[i] = gallery[i]; 
	}

	delete[] gallery; 
	gallery = resized;
	capacity = newCap;
}

Gallery::Gallery(): size(0), capacity(INITIAL_CAP)
{
	this->gallery = new Image * [capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		gallery[i] = nullptr;
	}

}

Gallery::Gallery(Image** gallery, size_t size, size_t capacity):size(size), capacity(capacity)
{
	this->gallery = new Image * [capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		if (i < size && gallery[i] != nullptr) {
			this->gallery[i] = new Image(*gallery[i]);
		}
		else {
			this->gallery[i] = nullptr;
		}
			
	}
}

Gallery::Gallery(const Gallery& other)
{
	copyFrom(other);
}

Gallery& Gallery::operator=(const Gallery& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Gallery::Gallery(Gallery&& other) noexcept
{
	moveFrom(std::move(other));
}

Gallery& Gallery::operator=(Gallery&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Gallery::~Gallery()
{
	free();
}

void Gallery::add(Image* image)
{
	if (!image) {
		return;
	}

	if (size >= capacity) {
		resize(capacity * 2);
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i] == nullptr) {
			gallery[i] = new Image(*image);
			size++;
			return;
		}
	}
}

void Gallery::add(Image* image, size_t index)
{
	if (!image || index >= capacity || gallery[index] != nullptr) {
		return;
	}
		

	gallery[index] = new Image(*image);
	size++;
}

void Gallery::remove(size_t index)
{
	if (index >= capacity || gallery[index]==nullptr) {
		return;
	}

	delete gallery[index];
	gallery[index] = nullptr;
	size--;
}

void Gallery::showEmpty()
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i] == nullptr) {
			std::print("{} ", i);
		}
	}

	std::println("");
}

void Gallery::clear()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete gallery[i];
		gallery[i] = nullptr;
		
	}

	size = 0;
}

Image* Gallery::operator[](size_t index)
{
	if (index >= capacity) {
		return nullptr;
	}
		
	return gallery[index];
}

size_t Gallery::getSize()
{
	return size;
}

Gallery Gallery::filter(ImageType type)
{
	Gallery result;
	
	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i] && gallery[i]->getType() == type) {
			result.add(gallery[i]);
		}
	}

	return result;
}

void Gallery::applyToAll(std::function<void(Image*)> op)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i]) {
			op(gallery[i]);
		}
			
	}
}

Gallery& Gallery::operator+=(const Gallery& other)
{
	for (size_t i = 0; i < other.capacity; i++)
	{
		if (other.gallery[i]) {
			add(other.gallery[i]);
		}
	}

	return *this;
}

Gallery Gallery::operator+(const Gallery& other) const
{
	Gallery result(*this);
	result += other;
	return result;
}

Image* Gallery::findLargest()
{
	Image* largest = nullptr;
	int maxPixels = -1;

	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i]) {
			int pixels = gallery[i]->getWidth() * gallery[i]->getHeight();

			if (pixels >= maxPixels) {
				maxPixels = pixels;
				largest = gallery[i];
			}
		}
	}

	return largest;
}

void Gallery::saveAll(const char* directory)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (gallery[i]) {
			
			char indexStr[16];
			intToString(i, indexStr);

			char path[256] = "";
			//std::strcat(path, directory);
			//std::strcat(path, "image_");
			//std::strcat(path, indexStr);

			gallery[i]->saveImage(path);
		}
	}
}

void Gallery::intToString(size_t num, char* buffer)
{
	if (num == 0) {
		buffer[0] = '0';
		buffer[1] = '\0';
	}

	char temp[16];
	int i = 0;

	while (num > 0) {
		temp[i++] = (num % 10) + '0';
		num /= 10;
	}

	int j = 0;
	while (i > 0) {
		buffer[j++] = temp[i--];
	}

	buffer[j] = '\0';
}


