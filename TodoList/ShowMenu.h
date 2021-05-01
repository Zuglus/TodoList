#pragma once

#include <iostream>

using namespace std;

void ShowMenu(void(*menu), const char* names[], const int size)
{
	cout << "\nМеню:\n";

	while (1)
	{
		for (int i = 0; i < size; ++i)
			cout << names[i] << endl;

		int selected;
		while (1)
		{
			cout << ">>> Выберите пункт меню:\n";
			cin >> selected;

			if (selected >= 1 &&
				selected <= 6)
				break;

			cout << "Ошибочный выбор!\n";
		}


	}
}