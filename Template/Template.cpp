#include "Template.h"
#include <iostream>
using namespace std;  

template <typename T> IntArray<T>::IntArray() = default; //����������� �������� ������� �� ���������


template <typename T> IntArray<T>::IntArray(int length) : m_length{ length }    //����������� �������� ������� � ������� ��������, �������� ���-�.
{
    if (length <= 0)
    {
        throw "������ �� ����� ���� ������ ��� ����� 0";
    }
    if (length > 0)
        m_data = new T[length] {};
    cout << "������ ������ �������� " << length << endl;
}

template <typename T> IntArray<T>::~IntArray()   //���������� ��������� ������ �������
{
    delete[] m_data;
}


template <typename T> void IntArray<T>::erase()  //����������� ���������� ������ �������
{
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
}


template <typename T> T IntArray<T>::getLength()  //������� ���������� ������ �������
{
    return m_length;
}

template <typename T> void IntArray<T>::resize(int newLength)    //����������� ��������� ������� ������� � ������������ ���������
{
    if (newLength <= 0)
    {
        throw "������ ������� �� ����� ���� ������ �� �������� ������ ��� ������ 0";
    }

    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };    // ENG ������� �� ������ �������� ����� ������

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)   // ENG ������ �������� �������� ���� �� ������
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
    cout << "������ ������� ������ �� " << newLength << endl;
}
 

template <typename T> IntArray<T>& IntArray<T>::operator=(const IntArray& a)    //�������� ������������
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}


template <typename T> int& IntArray<T>::operator[](int index)    //����������� ������� � ����������� �������� �������
{
    if (index < 0 || index > m_length)
    {
        throw "��������� ������� ������� �� ������";
    }
    return m_data[index];
}


template <typename T> void IntArray<T>::reallocate(int newLength) //���-� �������� ������ �������. ��� ������������ �������� ����� ����������. ��� ������� �������� ������.
{
    erase();
    if (newLength <= 0)
    {
        throw "������ ������� �� ����� ���� ������ �� �������� ������ ��� ������ 0";
    }

    m_data = new int[newLength];
    m_length = newLength;
}


template <typename T> IntArray<T>::IntArray(IntArray& a)   //����������� �����������
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
    cout << "������� ����� ������� �������� " << a.m_length << endl;
}


template <typename T> void IntArray<T>::insertBefore(T value, int index)   //����������� ������� �������� � ������
{
    if (index < 0 || index > m_length)
    {
        throw "����� ������� ������� �� ������, ���������� �������� ����� �������";
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


template <typename T> void IntArray<T>::remove(int index)  //����������� �������� �������� �������
{
    if (index < 0 || index > m_length)
    {
        throw "����� ������� ������� �� ������, ���������� ������� ������� ";
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