#include <iostream>
#include <fstream>

void copyFile(const char* src, const char* dest) {
    std::ifstream is(src);
    std::ofstream os(dest);

    if (!is.is_open()) return;
    if (!os.is_open()) return;

    char buff[1024];

    while (is.getline(buff, 1024)) {
        os << buff << std::endl;
    }

    is.close();
    os.close();
}

int main() {
    copyFile("file.txt", "copy.txt");
}