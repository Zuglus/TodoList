#pragma once

#include <iostream>

using namespace std;

int ShowMenu( const char* names[], const int size)
{
		cout << "\nМеню:\n";
		for (int i = 0; i < size; ++i)
			cout << names[i] << endl;

		int selected;
		while (1)
		{
			cout << ">>> Выберите пункт меню:\n";
			cin >> selected;
			selected;
			if (selected - 1 >= 0 &&
				selected <= size)
				break;

			cout << "Ошибочный выбор!\n";
		}

			return selected;
}