#pragma once

#include <iostream>

using namespace std;

void ShowTodos(Todo* arr, int size)
{
	cout << "������ ���:\n";

	if (size)
		cout << "��� �����������";
	else
		cout << "\n��� �� �������������!!!\n";
}