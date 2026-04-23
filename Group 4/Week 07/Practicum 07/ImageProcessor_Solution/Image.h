//
// Created by Boris Bozhilov on 4/6/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H
#include <cstddef>


class Image {

private:

    // this fixes the type of the base image from which the other versions are created to PPM
    static constexpr int COUNT_OF_CHANNELS_BASE_IMAGE = 3;

    void copyDataFrom(const Image& other) const;

protected:

    // the pType variable stores the index after P in the header - used to determine the image type
    char pType = 0;
    int width = -1;
    int height = -1;
    unsigned char maxVal = 0;

    unsigned char*data = nullptr;

    void setToInvalidState();
    int getSizeOfData(int countOfChannels) const;

    virtual int getCountOfChannels() const = 0;

public:

    // rule of 5
    Image();
    explicit Image(const char* fileName);

    Image(const Image& other);
    Image& operator=(const Image& other);

    Image(Image&& other) noexcept;
    Image& operator=(Image&& other) noexcept;

    virtual ~Image();

    // predefining operators
    explicit operator bool() const;

    // creating the image stored
    virtual void createImage(const char* outputFileName) const;
};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IMAGE_H