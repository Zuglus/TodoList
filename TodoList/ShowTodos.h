#pragma once

using namespace std;

void ShowTodos(Todo* arr, int size)
{
	cout << "������ ���:\n";

	if (size)
		for (int i = 0; i < size; ++i)
		{
			cout << "\nID: " << i << endl;
			cout << "������������: " << arr[i].name << endl;
			cout << "���������: ";
			switch (arr[i].priority)
			{
			case 1:
				cout << "������";
				break;
			case 2:
				cout << "�������";
				break;
			case 3:
				cout << "�������";
				break;
			}
			cout << "\n�����������: " << arr[i].description;
			cout << "\n���� ����������: " << arr[i].data.day << '.';
			cout << arr[i].data.month << '.';
			cout << arr[i].data.year << " � ";
			cout << arr[i].data.hour << ':' << arr[i].data.minuts << endl;
		}
	else
		cout << "\n��� �� �������������!!!\n";
}