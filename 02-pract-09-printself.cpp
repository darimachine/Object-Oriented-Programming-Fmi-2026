#include <iostream>
#include <fstream>

void printSelf(const char* fileName) {
    std::ifstream is(fileName);

    if (!is.is_open()) return;

    char buff[1024];

    while (is.getline(buff, 1024)) {
        std::cout << buff << std::endl;
    }

    is.close();
}

int main() {
	printSelf("file.txt");
}