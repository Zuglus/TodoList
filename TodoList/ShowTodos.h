#pragma once

using namespace std;

void ShowTodos(Todo* arr, int size)
{
	cout << "Список дел:\n";

	if (size)
		for (int i = 0; i < size; ++i)
		{
			cout << "\nID: " << i << endl;
			cout << "Наименование: " << arr[i].name << endl;
			cout << "Приоритет: ";
			switch (arr[i].priority)
			{
			case 1:
				cout << "низкий";
				break;
			case 2:
				cout << "средний";
				break;
			case 3:
				cout << "высокий";
				break;
			}
			cout << "\nПодробности: " << arr[i].description;
			cout << "\nСрок исполнения: " << arr[i].data.day << '.';
			cout << arr[i].data.month << '.';
			cout << arr[i].data.year << " к ";
			cout << arr[i].data.hour << ':' << arr[i].data.minuts << endl;
		}
	else
		cout << "\nДел не запланировано!!!\n";
}