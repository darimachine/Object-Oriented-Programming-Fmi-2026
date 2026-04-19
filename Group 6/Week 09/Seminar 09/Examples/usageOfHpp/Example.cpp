#include "Example.h"

template <typename T>
Example<T>::Example(const T& obj) : obj(obj) {}

template <typename T>
const T& Example<T>::getValue() const {
    return obj;
}

template <typename T>
void Example<T>::setValue(const T& obj) {
    this->obj = obj;
}

// we declare that we will use this class with int and with bool
template class Example<int>;
template class Example<bool>;
