#include <iostream>
#include <fstream>
#include <print>

int getSize(const char* fileName) {
    std::ifstream is(fileName);

    if (!is.is_open()) return -1;

    is.seekg(0, std::ios::end);
    int size = is.tellg();

    is.close();

    return size;
}

int countOfOccurrences(const char* fileName, char ch) {
    std::ifstream is(fileName);

    if (!is.is_open()) return -1;

    int occurrences = 0;
    char curr;

    while (is.get(curr)) {
        if (curr == ch) {
            occurrences++;
        }
    }

    is.close();

    return occurrences;
}

int countOfRows(const char* fileName) {
    std::ifstream is(fileName);

    if (!is.is_open()) return -1;

    int rows = 0;
    char buff[1024];

    while (is.getline(buff, 1024)) {
        rows++;
    }

    is.close();

    return rows;
}

int main() {
    std::println("File size: {}", getSize("file.txt"));
    std::println("Count of occurrences of {}: {}", '2', countOfOccurrences("file.txt", '2'));
    std::println("Count of rows: {}", countOfRows("file.txt"));
}