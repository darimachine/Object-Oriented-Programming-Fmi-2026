//
// Created by Boris Bozhilov on 4/10/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_INVERTEDIMAGE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_INVERTEDIMAGE_H
#include "Image.h"


class InvertedImage : public Image{

private:

    static constexpr int COUNT_OF_CHANNELS_PPM = 3;

protected:

    int getCountOfChannels() const override { return COUNT_OF_CHANNELS_PPM;}

public:

    InvertedImage();
    explicit InvertedImage(const char* fileName);

    InvertedImage(const InvertedImage& other);
    InvertedImage &operator=(const InvertedImage &other);

    InvertedImage(InvertedImage&& other) noexcept;
    InvertedImage& operator=(InvertedImage&& other) noexcept;

    ~InvertedImage() override;
};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_INVERTEDIMAGE_H