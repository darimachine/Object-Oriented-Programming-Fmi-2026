#include "SavePPM.h"

void SavePPM::function_savePPM(Image &img, const char *filename, size_t width, size_t height) {
    std::ofstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Cannot open output file: " << filename << "\n";
        return;
    }

    file << "P6\n";
    file << width << " " << height << "\n";
    file << 255 << "\n";

    const unsigned char* bytes = img.getBytes();
    file.write(reinterpret_cast<const char*>(bytes), img.getByteCount());
}