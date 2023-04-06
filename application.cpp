#include "pointer_array_lib.h"



int main()
{
	int size = 10;
	int * array = create<int>(size);
	random<int>(array, size);
	do
	{
		system("cls");
		cout << "size : " << size << endl;
		print<int>(array, size);
		cout << "Enter value: ";
		int value;
		cin >> value;
		cout << "Enter index: ";
		int index;
		cin >> index;
		insert<int>(array, size, value, index);
		cout << "----------after push item-----------------" << endl;
		cout << "size : " << size << endl;
		print<int>(array, size);
		system("pause");
	} while (true);
	_delete<int>(array);
	return 0;
}