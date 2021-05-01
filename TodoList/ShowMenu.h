#pragma once

#include <iostream>

using namespace std;

void ShowMenu(void (*menu[])(Todo* x, int y), const char* names[], const int size, Todo* arr, int arrSize)
{
	while (1)
	{
		cout << "\n����:\n";
		for (int i = 0; i < size; ++i)
			cout << names[i] << endl;

		int selected;
		while (1)
		{
			cout << ">>> �������� ����� ����:\n";
			cin >> selected;
			--selected;
			if (selected >= 0 &&
				selected <= size)
				break;

			cout << "��������� �����!\n";
		}

		if (selected == size - 1)
		{
			cout << "\n����� �� ���������...\n";
			break;
		}
		else
			(*menu[selected])(arr, arrSize);
	}
}