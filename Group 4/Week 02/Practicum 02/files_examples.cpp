#include <iostream>
#include <fstream>
#include <print>
#include <format>

using std::cout;
using std::endl;

void bits() {
    std::ofstream ofs("nqmame.txt", std::ios::_Nocreate);
    ofs.put('a');
    cout << ofs.bad() << endl;  // raised on "serious" IO error - couldnt open file, low-level buffer error,
                                // exception is thrown during IO operations
    cout << ofs.fail() << endl; // raised on unsuccessful formatted input operation
                                // also when bad() is raised
    cout << ofs.good() << endl;

    ofs.clear();

    cout << ofs.bad() << endl; 
    cout << ofs.good() << endl;

    ofs.close();

    int num;
    std::cin >> num;
    cout << std::cin.bad() << endl;
    cout << std::cin.fail() << endl;
    cout << std::cin.good() << endl;
}

void printSelf() {
    std::ifstream ifs("tatata.cpp");
    if (!ifs.is_open()) {
        return;
    }

    while (!ifs.eof())
    {
        char buf[1024];
        ifs.getline(buf, 1024);
        cout << buf << endl;
    }
}

void f() {
    std::ifstream ifs("file.txt");
    if (!ifs.is_open()) {
        return;
    }

    int num;
    ifs >> num;
    std::println("Num: {}", num);
    ifs.ignore();
    char buf[1024];
    ifs.getline(buf, 1024);
    std::println("Buffer 1: {}", buf);
    
    /*ifs.getline(buf, 1024);
    std::println("Buffer 2: {}", buf);*/

    ifs.close();
}

int fileSize(const char* file) {
    std::ifstream ifs(file);
    if (!ifs.is_open()) {
        return -1;
    }

    ifs.seekg(0, std::ios::end);
    auto size = ifs.tellg();

    ifs.close();

    return size;
}

int main()
{
    /*
    const char* file = "file.txt";
    std::println("\"{}\" size: {}B", file, fileSize(file));*/

    bits();
}
