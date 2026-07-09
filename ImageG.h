#pragma once

enum class ImageType {
	PPM, PGM, UNKNOWN
};

class Image
{
private:
	int width = 0;
	int height = 0;
	ImageType type;
	static constexpr int maxval = 255;

	unsigned char* bytes = nullptr;

	void copyFrom(const Image&);
	void free();
	void moveFrom(Image&&);

public:
	Image();
	Image(int, int, ImageType, const unsigned char*);
	Image(const Image&);
	Image& operator=(const Image&);
	~Image();

	Image(Image&&) noexcept;
	Image& operator=(Image&&) noexcept;

	int getWidth() const;
	int getHeight()const;
	ImageType getType()const;

	void saveImage(const char*);
};


Image readImage(const char*);

