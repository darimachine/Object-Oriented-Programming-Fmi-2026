#include <iostream>
#include <fstream>

void mergeSort(const char* src1, const char* src2, const char* dest) {
    std::ifstream is1(src1);
    std::ifstream is2(src2);
    std::ofstream os(dest);

    if (!is1.is_open()) return;
    if (!is2.is_open()) return;
    if (!os.is_open()) return;

    int num1;
    int num2;

    bool hasNum1 = (bool)(is1 >> num1);
    bool hasNum2 = (bool)(is2 >> num2);

    while (hasNum1 && hasNum2) {
        if (num1 < num2) {
            os << num1 << ' ';
            hasNum1 = (bool)(is1 >> num1);
        }
        else {
            os << num2 << ' ';
            hasNum2 = (bool)(is2 >> num2);
        }
    }

    while (hasNum1) {
        os << num1 << ' ';
        hasNum1 = (bool)(is1 >> num1);
    }
        
    is1.close();
    
    while (hasNum2) {
        os << num2 << ' ';
        hasNum2 = (bool)(is2 >> num2);
    }

    is2.close();

    os.close();
}

int main() {
    mergeSort("src1.txt", "src2.txt", "dest.txt");
}