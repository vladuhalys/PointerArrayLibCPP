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
		cout << "Menu: 1 - push, 2 - remove" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "Enter index: ";
			int index;
			cin >> index;
			insert<int>(array, size, value, index);
		}break;
		case 2:
		{
			if (remove_at<int>(array, size, value)) {
				cout << "Item was remove" << endl;
			}
			else
			{
				error_message("Item not found" << endl);
			}
			
		}break;
		}
		cout << "----------after change-----------------" << endl;
		cout << "size : " << size << endl;
		print<int>(array, size);
		system("pause");
	} while (true);
	_delete<int>(array);
	return 0;
}