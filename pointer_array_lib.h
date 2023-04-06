#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

#define RED 12
#define GREEN 10
#define YELLOW 14
#define DEFAULT 7

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define error_message(message) { \
SetConsoleTextAttribute(hConsole, RED);\
cout << message;\
SetConsoleTextAttribute(hConsole, DEFAULT);}

#define access_message(message) { \
SetConsoleTextAttribute(hConsole, GREEN);\
cout << message;\
SetConsoleTextAttribute(hConsole, DEFAULT);}

#define warning_message(message) { \
SetConsoleTextAttribute(hConsole, YELLOW);\
cout << message;\
SetConsoleTextAttribute(hConsole, DEFAULT);}

int last_index_push = -1;
int last_index_remove = -1;

void change_last_index(int index)
{
	last_index_push = index;
}

template<typename T>
T* create(int size)
{
	T* array = new T[size];
	return array;
}

template<typename T>
void random(T* array, int size = 1)
{
	srand(time(0));
	if (array == nullptr)
	{
		cout << "Array is empty" << endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

template<typename T>
void print(T* _array, int size = 1)
{
	if (_array == nullptr)
	{
		cout << "Array is empty" << endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (i == last_index_push)
		{
			access_message(_array[i]); cout << " ";
		}
		/*else if (i == prev_last_index_push)
		{
			warning_message(_array[i]); cout << " ";
		}*/
		else
		{
			cout << _array[i] << " ";
		}
	}
	cout << endl;
}

template<typename T>
void _delete(T* array)
{
	delete[] array;
}



template<typename T>
void push_back(T* &array, int &size, T element)
{
	T * temp = new T[size+1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	change_last_index(size);
	temp[size] = element;
	++size;
	array = temp;
	
}
template<typename T>
void push_front(T* &array, int &size, T element)
{
	T* temp = new T[size + 1];
	temp[0] = element;
	++size;
	for (size_t i = 1; i < size; i++)
	{
		temp[i] = array[i-1];
	}
	
	array = temp;
	change_last_index(0);
}

template<typename T>
void insert(T* &array, int &size, T element, int index)
{
	
	if (index < 0 || index > size)
	{
		cout << "Index is out of range" << endl;
		return;
	}
	if (index == 0)
	{
		push_front<T>(array, size, element);
		return;
	}
	else if (index == size)
	{
		push_back<T>(array, size, element);
		return;
	}
	change_last_index(index);
	++size;
	T* temp = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		if(i < index)
			temp[i] = array[i];
		else if (i == index)
			temp[i] = element;
		else
			temp[i] = array[i - 1];
	}
	array = temp;
}