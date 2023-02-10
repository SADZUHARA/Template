#include "Template.cpp"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	try
	{
		int r = 6; // ������ �������
		IntArray <int> arr(r);	//������ ������ �������� "r"
		cout << endl;

		arr.erase();
		cout << "������ ������� ������ "  << endl; //�������� ������ ������� arr
		cout << endl;

		cout << "������� ������ ������� " << arr.getLength() << endl;	//������� ������� ������ �������
		cout << endl;

		arr.resize(10);	//������ ������� ������ ������� �� ������ 10
		cout << endl;

		int sum = 10;
		for (int i = 0; i < arr.getLength(); i++)	//������������ ��������� ������� ��������
		{
			arr[i] = sum;
			sum += 10;
		}

		for (int i = 0; i < arr.getLength(); i++)	//���������� �������� ������� arr
		{
			cout << "������� " << i << " ����� " << arr.operator[](i) << endl; 
		}
		cout << endl;

		class IntArray <int> arrCopy(arr);	//������ ����� �������
		cout << endl;

		for (int i = 0; i < arrCopy.getLength(); i++)	//���������� �������� ������� arrCopy
		{
			cout << "������� " << i << " ����� " << arr.operator[](i) << endl;
		}
		cout << endl;

		
		arrCopy.insertBefore(99, 5);	//����������� 5�� �������� ������� arrCopy �������� 99
		cout << "������� " << 5 << " ����� " << arrCopy.operator[](5) << endl;
		cout << endl;

		for (int i = 0; i < arrCopy.getLength(); i++)	//���������� �������� ������� arrCopy
		{
			cout << "������� " << i << " ����� " << arrCopy.operator[](i) << endl;
		}
		cout << endl;


		arrCopy.remove(6);	//������� 6� ������� ������� arrCopy
		for (int i = 0; i < arrCopy.getLength(); i++)	//���������� �������� ������� arrCopy
		{
			cout << "������� " << i << " ����� " << arrCopy.operator[](i) << endl;
		}
		cout << endl;



	
	}

	catch (const char* exception)
	{
		cout << "����������: " << exception << endl;
	}

	return 0;
}