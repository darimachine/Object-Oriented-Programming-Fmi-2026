#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>   // std::accumulate

int main() {
    using std::cout;
    using std::vector;

    // Construction
    vector<int> v1;                     // empty vector
    vector<int> v2 = {1, 2, 3, 4, 5};   // initializer list
    vector<int> v3(5);                  // 5 elements initialized to 0
    vector<int> v4(4, 7);               // 4 elements, each equal to 7
    vector<int> v5(v2.begin(), v2.end()); // range constructor
    vector<int> v6 = v2;                // copy
    vector<int> v7 = std::move(v6);     // move

    cout << "v2: ";
    for (int x : v2) cout << x << ' ';
    cout << "\n\n";

    // Size / capacity
    cout << "v2.size()     = " << v2.size() << '\n';
    cout << "v2.empty()    = " << std::boolalpha << v2.empty() << '\n';
    cout << "v2.capacity() = " << v2.capacity() << "\n\n";

    // Element access
    cout << "v2[0]      = " << v2[0] << '\n';
    cout << "v2.at(1)   = " << v2.at(1) << '\n';
    cout << "v2.front() = " << v2.front() << '\n';
    cout << "v2.back()  = " << v2.back() << "\n\n";

    // Modifiers: push_back / emplace_back / pop_back
    v2.push_back(6);
    v2.emplace_back(7);

    cout << "after push_back/emplace_back: ";
    for (int x : v2) cout << x << ' ';
    cout << '\n';

    v2.pop_back();
    cout << "after pop_back: ";
    for (int x : v2) cout << x << ' ';
    cout << "\n\n";

    // Insert
    v2.insert(v2.begin() + 2, 99);             // insert single element
    v2.insert(v2.end(), 2, 100);               // insert count copies
    vector<int> extra = {200, 300};
    v2.insert(v2.end(), extra.begin(), extra.end()); // insert range

    cout << "after insert: ";
    for (int x : v2) cout << x << ' ';
    cout << "\n\n";

    // Erase
    v2.erase(v2.begin() + 2);                  // erase one element
    v2.erase(v2.end() - 2, v2.end());          // erase range

    cout << "after erase: ";
    for (int x : v2) cout << x << ' ';
    cout << "\n\n";

    // Assign
    v3.assign(3, 42);                          // replace contents with 3 copies of 42
    cout << "v3 after assign: ";
    for (int x : v3) cout << x << ' ';
    cout << "\n\n";

    // Resize
    v3.resize(5, -1);                          // grow and fill new elements with -1
    cout << "v3 after resize(5, -1): ";
    for (int x : v3) cout << x << ' ';
    cout << '\n';

    v3.resize(2);                              // shrink
    cout << "v3 after resize(2): ";
    for (int x : v3) cout << x << ' ';
    cout << "\n\n";

    // Reserve / shrink_to_fit
    vector<int> cap;
    cout << "cap.capacity() before reserve = " << cap.capacity() << '\n';
    cap.reserve(50);
    cout << "cap.capacity() after reserve  = " << cap.capacity() << '\n';
    cap.push_back(1);
    cap.push_back(2);
    cap.shrink_to_fit();
    cout << "cap.capacity() after shrink_to_fit = " << cap.capacity() << "\n\n";

    // Clear
    vector<int> temp = {10, 20, 30};
    temp.clear();
    cout << "temp.empty() after clear = " << temp.empty() << "\n\n";

    // Iterators
    vector<int> it = {5, 1, 4, 2, 3};

    cout << "iterate with iterator: ";
    for (auto iter = it.begin(); iter != it.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << '\n';

    cout << "reverse iterate: ";
    for (auto iter = it.rbegin(); iter != it.rend(); ++iter) {
        cout << *iter << ' ';
    }
    cout << "\n\n";

    // Algorithms with vector
    std::sort(it.begin(), it.end());
    cout << "after sort: ";
    for (int x : it) cout << x << ' ';
    cout << '\n';

    std::reverse(it.begin(), it.end());
    cout << "after reverse: ";
    for (int x : it) cout << x << ' ';
    cout << '\n';

    int sum = std::accumulate(it.begin(), it.end(), 0);
    cout << "sum = " << sum << "\n\n";

    // Data pointer
    vector<int> raw = {11, 22, 33};
    int* ptr = raw.data();
    cout << "raw.data()[0] = " << ptr[0] << '\n';
    cout << "raw.data()[1] = " << ptr[1] << "\n\n";

    // Swap
    vector<int> a = {1, 2, 3};
    vector<int> b = {9, 8};
    a.swap(b);

    cout << "after swap, a: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';

    cout << "after swap, b: ";
    for (int x : b) cout << x << ' ';
    cout << "\n\n";

    // Comparison
    vector<int> c1 = {1, 2, 3};
    vector<int> c2 = {1, 2, 4};

    cout << "(c1 == c2) = " << (c1 == c2) << '\n';
    cout << "(c1 < c2)  = " << (c1 < c2) << '\n';

    return 0;
}
