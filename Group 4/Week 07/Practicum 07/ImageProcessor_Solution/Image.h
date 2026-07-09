//
// Created by Boris Bozhilov on 4/6/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H
#include <cstddef>


class Image {

private:

    static constexpr int COUNT_OF_CHANNELS_RGB = 3;

    // the pType variable stores the index after P in the header - used to determine the image type
    char pType = 0;
    int width = -1;
    int height = -1;
    unsigned char maxVal = 0;

    unsigned char*data = nullptr;

    int getSizeOfData() const;
    void setToInvalidState();
    void copyDataFrom(const Image& other) const;

public:

    // rule of 5
    Image();
    explicit Image(const char* fileName);

    Image(const Image& other);
    Image& operator=(const Image& other);

    Image(Image&& other) noexcept;
    Image& operator=(Image&& other) noexcept;

    ~Image();

    // predefining operators
    explicit operator bool() const;

    // creating the image stored
    void createImage(const char* outputFileName) const;
    void createInvertedImage(const char* outputFileName) const;
    void createGrayscaleImage(const char* outputFileName) const;
};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H