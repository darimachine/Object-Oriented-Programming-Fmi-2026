#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
void printVector(const std::vector<T>& v) {
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    // NON-MODIFYING ALGORITHMS
    // These algorithms read the range but do not change it

    // find() -> returns iterator to the first element equal to 5
    auto it = std::find(numbers.begin(), numbers.end(), 5);

    if (it != numbers.end()) {
        std::cout << "Found: " << *it << '\n';
    }

    // count_if() -> counts how many elements satisfy the condition
    // in this case counts the even numbers from the vector
    int evenCount = std::count_if(
        numbers.begin(),
        numbers.end(),
        [](int x) { return x % 2 == 0; }
    );

    std::cout << "Even count: " << evenCount << '\n';

    // all_of() -> checks if all elements satisfy the given condition
    bool allPositive = std::all_of(
        numbers.begin(),
        numbers.end(),
        [](int x) { return x > 0; }
    );
    std::cout << "All positive: " << std::boolalpha << allPositive << '\n';

    // accumulate() -> sums all elements in the iterator range
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << '\n';

    // for_each() -> applies a function to every element (read-only here)
    std::cout << "Elements: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << '\n';


    // MODIFYING ALGORITHMS
    // These algorithms change the contents of the vector

    // replace() -> replaces all occurrences of 2 with 20
    std::replace(numbers.begin(), numbers.end(), 2, 20);
    printVector(numbers);

    // transform() -> modifies each element by multiplying by 2
    std::transform(
        numbers.begin(),
        numbers.end(),
        numbers.begin(),
        [](int x) { return x * 2; }
    );
    printVector(numbers);

    // fill() -> overwrites all elements in the range with the same value
    std::fill(numbers.begin(), numbers.begin() + 2, 100);
    printVector(numbers);

    // reverse() -> reverses the order of the elements
    std::reverse(numbers.begin(), numbers.end());
    printVector(numbers);

    // sort() -> sorts the vector in ascending order
    std::sort(numbers.begin(), numbers.end());
    printVector(numbers);

    // remove_if() -> moves unwanted elements to the end and returns new logical end
    auto newEnd = std::remove_if(
        numbers.begin(),
        numbers.end(),
        [](int x) { return x > 50; }
    );
    printVector(numbers);
}
