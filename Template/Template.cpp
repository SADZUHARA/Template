#include "Template.h"
#include <iostream>
using namespace std;  

template <typename T> IntArray<T>::IntArray() = default; // онструктор создани€ массива по умолчанию


template <typename T> IntArray<T>::IntArray(int length) : m_length{ length }    // онструктор создани€ массива с заданым размером, основной кон-р.
{
    if (length <= 0)
    {
        throw "массив не может быть меньше или равен 0";
    }
    if (length > 0)
        m_data = new T[length] {};
    cout << "создан массив размером " << length << endl;
}

template <typename T> IntArray<T>::~IntArray()   //деструктор удал€ющий размер массива
{
    delete[] m_data;
}


template <typename T> void IntArray<T>::erase()  // онструктор обнул€ющий размер массива
{
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
}


template <typename T> T IntArray<T>::getLength()  //функци€ возвращает размер массива
{
    return m_length;
}

template <typename T> void IntArray<T>::resize(int newLength)    // онструктор изменени€ размера массива с копированием элементов
{
    if (newLength <= 0)
    {
        throw "размер массива не может быть изменЄн на значение меньше или равено 0";
    }

    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };    // ENG —начала мы должны выделить новый массив

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)   // ENG “еперь копируем элементы один за другим
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
    cout << "размер массива изменЄн на " << newLength << endl;
}
 

template <typename T> IntArray<T>& IntArray<T>::operator=(const IntArray& a)    //оператор присваивани€
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}


template <typename T> int& IntArray<T>::operator[](int index)    // онструктор доступа к опредеЄнному элементу массива
{
    if (index < 0 || index > m_length)
    {
        throw "указанный элемент массива не найден";
    }
    return m_data[index];
}


template <typename T> void IntArray<T>::reallocate(int newLength) //кон-р измен€ет размер массива. ¬се существующие элементы будут уничтожены. Ёта функци€ работает быстро.
{
    erase();
    if (newLength <= 0)
    {
        throw "размер массива не может быть изменЄн на значение меньше или равено 0";
    }

    m_data = new int[newLength];
    m_length = newLength;
}


template <typename T> IntArray<T>::IntArray(IntArray& a)   //конструктор копировани€
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
    cout << "создана копи€ массива размером " << a.m_length << endl;
}


template <typename T> void IntArray<T>::insertBefore(T value, int index)   // онструктор вставки элемента в массив
{
    if (index < 0 || index > m_length)
    {
        throw "такой элемент массива не найден, невозможно вставить новый элемент";
    }

    int* data{ new int[m_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}


template <typename T> void IntArray<T>::remove(int index)  // онструктор удаление элемента массива
{
    if (index < 0 || index > m_length)
    {
        throw "такой элемент массива не найден, невозможно удалить элемент ";
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
}