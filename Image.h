#pragma once
class Image
{
private:
	int width=0;
	int height = 0;
	static constexpr int maxval = 255;

	unsigned char* bytes = nullptr;

	void copyFrom(const Image&);
	void free();
	void moveFrom(Image&&);

public:
	Image();
	Image(int, int, const unsigned char*);
	Image(const Image&);
	Image& operator=(const Image&);
	~Image();

	Image(Image&&) noexcept;
	Image& operator=(Image&&) noexcept;

	int getWidth() const;
	int getHeight()const;

	const unsigned char& operator[](int index)const;
};

Image readImage(const char* filename);

