#pragma once
#include <stdexcept>
template<typename T>
class Vector {
private:
    T* els;
    size_t size;
    size_t capacity;


    void copy(const Vector<T>& other);
    void resize(size_t newCap);
    void free();

public:
    Vector();
    ~Vector();

    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);

    Vector(size_t n);
    Vector(size_t n, const T& elem);
    void push_back(const T& elem);
    void pop_back();
    void insert(size_t idx, const T& elem);
    void erase(size_t idx);
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    void shrink_to_fit();
    void clear();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    bool empty() const;
    size_t getSize() const;
    size_t getCapacity() const;


};

template<typename T>
void Vector<T>::copy(const Vector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    els = new T[capacity];
    for (int i = 0;i < size;i++) {
        els[i] = other.els[i];
    }
}
template<typename T>
void Vector<T>::resize(size_t newCap) {
    T* newels = new T[newCap];
    for (int i = 0;i < size;i++) {
        newels[i] = els[i];
    }
    delete[] els;
    els = newels;
    this->capacity = newCap;
}
template<typename T>
void Vector<T>::free() {
    delete[] els;
    els = nullptr;
}
template<typename T>
Vector<T>::Vector() {
    capacity = 8;
    size = 0;
    els = new T[capacity]{};

}
template<typename T>
Vector<T>::~Vector() {
    free();
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    copy(other);
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}
template<typename T>
Vector<T>::Vector(size_t n) {
    size = n;
    capacity = n;
    els = new T[capacity]{};
}
template<typename T>
Vector<T>::Vector(size_t n, const T& elem) {
    size = n;
    capacity = n;
    els = new T[capacity];
    for (int i = 0;i < size;i++) {
        els[i] = elem;
    }
}
template<typename T>
void Vector<T>::push_back(const T& elem) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    els[size++] = elem;
}
template<typename T>
void Vector<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Out of range!");
    }
    size--;
}
template<typename T>
void Vector<T>::insert(size_t idx, const T& elem) {
    if (idx >= size) {
        throw std::out_of_range("Out of range!");
    }
    if (size == capacity) {
        resize(capacity * 2);
    }
    T* newels = new T[capacity];
    int l = 0;
    for (int i = 0;i < size;i++) {
        if (idx == i) {
            newels[l++] = elem;

        }
        newels[l++] = els[i];
    }
    size++;
    delete[] els;
    els = newels;
}
template<typename T>
void Vector<T>::erase(size_t idx) {
    if (idx >= size || empty()) {
        throw std::out_of_range("Out of range!");
    }
    T* newels = new T[capacity];
    int l = 0;
    for (int i = 0;i < size;i++) {
        if (idx == i) continue;
        newels[l++] = els[i];
    }
    size--;
    delete[] els;
    els = newels;
}
template<typename T>
const T& Vector<T>::operator[](size_t idx) const {
    if (idx >= size) {
        throw std::out_of_range("Out of range!");
    }
    return els[idx];
}
template<typename T>
T& Vector<T>::operator[](size_t idx) {
    if (idx >= size) {
        throw std::out_of_range("Out of range!");
    }
    return els[idx];
}
template<typename T>
void Vector<T>::shrink_to_fit() {
    resize(size);
}
template<typename T>
void Vector<T>::clear() {
    size = 0;
}
template<typename T>
const T& Vector<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Out of range!");
    }
    return els[0];
}
template<typename T>
const T& Vector<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Out of range!");
    }
    return els[size - 1];
}
template<typename T>
T& Vector<T>::front() {
    if (empty()) {
        throw std::out_of_range("Out of range!");
    }
    return els[0];
}
template<typename T>
T& Vector<T>::back() {
    if (empty()) {
        throw std::out_of_range("Out of range!");
    }
    return els[size - 1];
}
template<typename T>
bool Vector<T>::empty() const {
    return size == 0;
}
template<typename T>
size_t Vector<T>::getSize() const {
    return size;
}
template<typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}
