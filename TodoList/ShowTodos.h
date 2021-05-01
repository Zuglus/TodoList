#pragma once

#include <iostream>

using namespace std;

void ShowTodos(Todo* arr, int size)
{
	cout << "Список дел:\n";

	if (size)
		cout << "Дел невпроворот";
	else
		cout << "\nДел не запланировано!!!\n";
}