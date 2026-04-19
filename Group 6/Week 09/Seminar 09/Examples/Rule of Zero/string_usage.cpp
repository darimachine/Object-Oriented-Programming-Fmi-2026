#include <iostream>
#include <string>
#include <algorithm>

int main() {
    using std::cout;
    using std::string;

    // Конструиране
    string s1;                      // empty string
    string s2 = "Hello";            // from C-string
    string s3("Stefo");             // constructor
    string s4(5, '*');              // "*****"
    string s5 = s2 + " " + s3;      // concatenation

    cout << "s1 = [" << s1 << "]\n";
    cout << "s2 = " << s2 << "\n";
    cout << "s3 = " << s3 << "\n";
    cout << "s4 = " << s4 << "\n";
    cout << "s5 = " << s5 << "\n\n";

    // size / length / empty
    cout << "s5.size()   = " << s5.size() << "\n";
    cout << "s5.length() = " << s5.length() << "\n";
    cout << "s1.empty()  = " << std::boolalpha << s1.empty() << "\n\n";

    // Access symbols at index
    cout << "s2[1]    = " << s2[1] << "\n";
    cout << "s2.at(1) = " << s2.at(1) << "\n";
    cout << "s2.front() = " << s2.front() << "\n";
    cout << "s2.back()  = " << s2.back() << "\n\n";

    // Modification of string
    s2.push_back('!');
    cout << "after push_back: " << s2 << "\n";

    s2.pop_back();
    cout << "after pop_back:  " << s2 << "\n";

    s2 += " there";
    cout << "after += :       " << s2 << "\n";

    s2.append("!!!");
    cout << "after append:    " << s2 << "\n";

    s2.insert(5, ",");
    cout << "after insert:    " << s2 << "\n";

    s2.erase(5, 1);
    cout << "after erase:     " << s2 << "\n";

    s2.replace(6, 5, "WORLD");
    cout << "after replace:   " << s2 << "\n\n";

    // substr
    string sub = s2.substr(6, 5);
    cout << "substr(6, 5) = " << sub << "\n\n";

    // find / rfind
    size_t pos = s2.find("WORLD");
    if (pos != string::npos) {
        cout << "\"WORLD\" found at index " << pos << "\n";
    }

    pos = s2.rfind('!');
    if (pos != string::npos) {
        cout << "last '!' at index " << pos << "\n";
    }

    pos = s2.find_first_of("AEIOU");
    if (pos != string::npos) {
        cout << "first uppercase vowel at index " << pos << "\n";
    }

    pos = s2.find_last_not_of('!');
    if (pos != string::npos) {
        cout << "last char different from '!' at index " << pos << "\n";
    }
    cout << "\n";

    // compare
    string a = "abc";
    string b = "abd";
    cout << "a.compare(b) = " << a.compare(b) << "\n";
    cout << "(a < b)      = " << (a < b) << "\n\n";

    // capacity / reserve / resize / clear
    string cap = "test";
    cout << "capacity before reserve: " << cap.capacity() << "\n";
    cap.reserve(100);
    cout << "capacity after reserve:  " << cap.capacity() << "\n";

    cap.resize(10, '_');
    cout << "after resize(10, '_'): [" << cap << "]\n";

    cap.clear();
    cout << "after clear(), empty = " << cap.empty() << "\n\n";

    // c_str / data
    string text = "sample";
    const char* cstr = text.c_str();
    const char* raw  = text.data();
    cout << "c_str() = " << cstr << "\n";
    cout << "data()  = " << raw  << "\n\n";

    // swap
    string x = "one";
    string y = "two";
    x.swap(y);
    cout << "after swap: x = " << x << ", y = " << y << "\n\n";

    // iterators
    string it = "abcde";
    cout << "iterate: ";
    for (char ch : it) {
        cout << ch << ' ';
    }
    cout << "\n";

    std::reverse(it.begin(), it.end());
    // or alternatively: std::ranges::reverse(it);
    cout << "after reverse(begin, end): " << it << "\n\n";

    // C++20
    cout << "starts_with(\"He\") = " << s5.starts_with("He") << "\n";
    cout << "ends_with(\"ld\")   = " << s5.ends_with("ld") << "\n";

    // C++23
    cout << "contains(\"lo\")    = " << s5.contains("lo") << "\n";
    
    return 0;
}
