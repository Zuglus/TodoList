#pragma once

#include <iostream>

using namespace std;

void ShowMenu(void(*menu), const char* names[], const int size)
{
	cout << "\n����:\n";

	while (1)
	{
		for (int i = 0; i < size; ++i)
			cout << names[i] << endl;

		int selected;
		while (1)
		{
			cout << ">>> �������� ����� ����:\n";
			cin >> selected;

			if (selected >= 1 &&
				selected <= 6)
				break;

			cout << "��������� �����!\n";
		}


	}
}