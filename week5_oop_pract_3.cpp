#include <iostream>
#include <print>
#include "MultiSet.h"

int main() {
    MultiSet ms1(10);

    ms1.add(3);
    ms1.add(3);
    ms1.add(3);
    ms1.add(3); 

    ms1.add(5);
    ms1.add(5);

    std::print("ms1: ");
    ms1.print();

    MultiSet ms2(10);
    ms2.add(3);
    ms2.add(5);
    ms2.add(5);
    ms2.add(7);

    std::print("ms2: ");
    ms2.print();

    std::println("Count of 3 in ms1:{} ", (int)ms1.count(3));

    ms1.remove(3);
    std::print("ms1 after remove 3: ");
    ms1.print();

    MultiSet inter = MultiSet::intersection(ms1, ms2);
    std::print("Intersection: ");
    inter.print();

    MultiSet uni = MultiSet::unionSet(ms1, ms2);
    std::print("Union: ");
    uni.print();

    MultiSet copy = ms1;
    std::print("Copy of ms1: ");
    copy.print();

    return 0;
}

