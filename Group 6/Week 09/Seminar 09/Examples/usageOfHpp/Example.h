#pragma once

template <typename T>
class Example {
public:
    Example(const T& obj);

    const T& getValue() const;
    void setValue(const T& obj);

private:
    T obj;
};
