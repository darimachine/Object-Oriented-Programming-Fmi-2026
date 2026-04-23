#pragma once

template <class T>
class UniquePtr {
public:
    UniquePtr(T* ptr);

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) noexcept;
    UniquePtr& operator=(UniquePtr&& other) noexcept;

    ~UniquePtr();

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;

    operator bool() const;

private:
    T* ptr = nullptr;
};

template <class T>
UniquePtr<T>::UniquePtr(T* ptr) : ptr(ptr) {}

template <class T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept {
    ptr = other.ptr;
    other.ptr = nullptr;
}

template <class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template <class T>
UniquePtr<T>::~UniquePtr() {
    delete ptr;
    ptr = nullptr;
}

template <class T>
T& UniquePtr<T>::operator*() {
    return *ptr;
}

template <class T>
const T& UniquePtr<T>::operator*() const {
    return *ptr;
}

template <class T>
T* UniquePtr<T>::operator->() {
    return ptr;
}

template <class T>
const T* UniquePtr<T>::operator->() const {
    return ptr;
}

template <class T>
UniquePtr<T>::operator bool() const {
    return ptr != nullptr;
}
