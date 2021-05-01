#pragma once

#include <iostream>

using namespace std;

void ShowMenu(void (*menu[])(Todo* x, int y), const char* names[], const int size, Todo* arr, int arrSize)
{
	while (1)
	{
		cout << "\nМеню:\n";
		for (int i = 0; i < size; ++i)
			cout << names[i] << endl;

		int selected;
		while (1)
		{
			cout << ">>> Выберите пункт меню:\n";
			cin >> selected;
			--selected;
			if (selected >= 0 &&
				selected <= size)
				break;

			cout << "Ошибочный выбор!\n";
		}

		if (selected == size - 1)
		{
			cout << "\nВыход из программы...\n";
			break;
		}
		else
			(*menu[selected])(arr, arrSize);
	}
}