#include "Template.cpp"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	try
	{
		int r = 6; // размер массива
		IntArray <int> arr(r);	//создаём массив размером "r"
		cout << endl;

		arr.erase();
		cout << "размер массива обнулён "  << endl; //обнуляем размер массива arr
		cout << endl;

		cout << "текущий размер массива " << arr.getLength() << endl;	//выводим текущий размер массива
		cout << endl;

		arr.resize(10);	//меняем текущий размер массива на размер 10
		cout << endl;

		int sum = 10;
		for (int i = 0; i < arr.getLength(); i++)	//присваеиваем элементам массива значения
		{
			arr[i] = sum;
			sum += 10;
		}

		for (int i = 0; i < arr.getLength(); i++)	//показываем елементы массива arr
		{
			cout << "элемент " << i << " равен " << arr.operator[](i) << endl; 
		}
		cout << endl;

		class IntArray <int> arrCopy(arr);	//создаём копию массива
		cout << endl;

		for (int i = 0; i < arrCopy.getLength(); i++)	//показываем елементы массива arrCopy
		{
			cout << "элемент " << i << " равен " << arr.operator[](i) << endl;
		}
		cout << endl;

		
		arrCopy.insertBefore(99, 5);	//присваиваем 5му элеметну массива arrCopy значение 99
		cout << "элемент " << 5 << " равен " << arrCopy.operator[](5) << endl;
		cout << endl;

		for (int i = 0; i < arrCopy.getLength(); i++)	//показываем елементы массива arrCopy
		{
			cout << "элемент " << i << " равен " << arrCopy.operator[](i) << endl;
		}
		cout << endl;


		arrCopy.remove(6);	//удаляем 6й элемент массива arrCopy
		for (int i = 0; i < arrCopy.getLength(); i++)	//показываем елементы массива arrCopy
		{
			cout << "элемент " << i << " равен " << arrCopy.operator[](i) << endl;
		}
		cout << endl;



	
	}

	catch (const char* exception)
	{
		cout << "Исключение: " << exception << endl;
	}

	return 0;
}