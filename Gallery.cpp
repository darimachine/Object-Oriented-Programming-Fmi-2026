#include "Gallery.h"
#include<print>

Gallery::Gallery():size(0),capacity(16)
{
	images = new Image*[capacity]{ nullptr };
}

Gallery::Gallery(size_t capacity):capacity(capacity)
{
	images = new Image * [capacity] {nullptr};
}

Gallery::~Gallery()
{
	free();
}

void Gallery::free()
{
	for (size_t i = 0;i < capacity;i++)
	{
		delete images[i];
		images[i] = nullptr;
	}

	delete[]images;
	images = nullptr;
	size = 0;
	capacity = 0;
}

void Gallery::copyFrom(const Gallery& other)
{
	capacity = other.capacity;
	size = other.size;

	images = new Image* [capacity] {nullptr};
	for (size_t i = 0;i < size;i++)
	{
		if (other.images[i])
		{
			images[i] = new Image(*other.images[i]);
		}
	}
}

void Gallery::moveFrom(Gallery&& other)
{
	images = other.images;
	capacity = other.capacity;
	size = other.size;

	other.images = nullptr;
	other.size = 0;
	other.capacity = 0;
}

Gallery::Gallery(Gallery&& other) noexcept
{
	moveFrom(std::move(other));
}

Gallery& Gallery::operator=(Gallery&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Gallery::Gallery(const Gallery& other)
{
	copyFrom(other);
}

Gallery& Gallery::operator=(const Gallery& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void Gallery::resize()
{
	size_t oldCap = capacity;
	capacity *= 2;
	Image** newImages = new Image * [capacity] {nullptr};

	for (size_t i = 0;i < oldCap;i++)
	{
		newImages[i] = images[i];
	}

	delete[]images;
	images = newImages;
}

void Gallery::add(Image* image)
{
	if (size == capacity)
	{
		resize();
	}

	images[size++] = image;
}

void Gallery::add(Image* image, size_t index)
{
	if (index >= capacity)
	{
		return;
	}

	if (images[index] == nullptr)
	{
		images[index] = image;
		size++;
	}
}

void Gallery::remove(size_t index)
{
	if (index >= capacity)
	{
		return;
	}
	
	if (images[index])
	{
		delete images[index];
		images[index] = nullptr;
		size--;
	}
}

void Gallery::showEmpty()const
{
	std::println("Empty places in the array:");

	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i] == nullptr)
		{
			std::print("{} ", i);
		}
	}
	std::println();
}

void Gallery::clear()
{
	for (size_t i = 0;i < capacity;i++)
	{
		delete images[i];
		images[i] = nullptr;
	}
	size = 0;
}

const Image* Gallery::operator[](size_t index)const
{
	if (index >= capacity)
	{
		return nullptr;
	}

	return images[index];
}

Image* Gallery::operator[](size_t index)
{
	if (index >= capacity)
		return nullptr;

	return images[index];
}

size_t Gallery::getSize()const
{
	return size;
}

Gallery Gallery::filter(ImageType type)const
{
	Gallery result;
	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i] != nullptr && images[i]->getType() == type)
		{
			result.add(new Image(*images[i]));
		}
	}
	return result;
}

void Gallery::applyToAll(std::function<void(Image*)> op)
{
	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i])
		{
			op(images[i]);
		}
	}
}

Gallery Gallery::operator+(const Gallery& other) const
{
	Gallery result;
	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i])
		{
			result.add(new Image(*images[i]));
		}
	}

	for (size_t i = 0;i < other.capacity;i++)
	{
		if (other.images[i])
		{
			result.add(new Image(*other.images[i]));
		}
	}

	return result;
}

const Image* Gallery::findLargest() const
{
	const Image* largest = nullptr;
	int maxPixels = INT_MIN;

	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i])
		{
			int pixels = images[i]->getWidth() * images[i]->getHeight();
			if (pixels > maxPixels)
			{
				maxPixels = pixels;
				largest = images[i];
			}
		}
	}
	return largest;
}


void Gallery::saveAll(const char* directory) const
{
	for (size_t i = 0;i < capacity;i++)
	{
		if (images[i])
		{
			ImageUtils::savePPM(directory,*images[i]);
		}
	}
}