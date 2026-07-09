#include "ImageUtils.h"

void ImageUtils::savePPM(const char* fileName, const Image& image)
{
    if (fileName == nullptr)
    {
        return;
    }

    std::ofstream out(fileName, std::ios::binary);
    if (!out.is_open())
    {
        return;
    }

    out << "P6\n" << image.getWidth() << " " << image.getHeight()
        << "\n" << image.getMaxval() << "\n";

    int size = image.getWidth() * image.getHeight() * 3;
    for (int i = 0; i < size; i++)
    {
        out.put(image[i]);
    }
    out.close();
}