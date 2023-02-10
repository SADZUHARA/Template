#pragma once
#include <iostream>
using namespace std;


template <typename T> class IntArray
{
private:
    int m_length{}; //размер массива
    T* m_data{};

public:
    IntArray();
    IntArray(int length);
    ~IntArray();
    void erase();
    T getLength();
    void resize(int newLength);
    IntArray<T>& operator=(const IntArray& a);
    //IntArray<T>& operator=(IntArray& a); //от ментора
    int& operator[](int index);
    IntArray(IntArray& a);
    void reallocate(int newLength);
    void insertBefore(T value, int index);
    void remove(int index);

};