//
// Created by Boris Bozhilov on 4/10/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_GREYSCALEIMAGE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_GREYSCALEIMAGE_H
#include "Image.h"


class GrayscaleImage : public Image{

private:

    static constexpr int COUNT_OF_CHANNELS_PGM = 1;

protected:

    int getCountOfChannels() const override { return COUNT_OF_CHANNELS_PGM;}

public:

    GrayscaleImage();
    explicit GrayscaleImage(const char* fileName);

    GrayscaleImage(const GrayscaleImage& other);
    GrayscaleImage& operator=(const GrayscaleImage& other);

    GrayscaleImage(GrayscaleImage&& other) noexcept;
    GrayscaleImage& operator=(GrayscaleImage&& other) noexcept;

    ~GrayscaleImage() override;
};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_GREYSCALEIMAGE_H