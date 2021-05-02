#include <windows.h>
#include <iostream>
#include "TodoStruct.h"
#include "ShowTodos.h"
#include "ShowMenu.h"
#include "AddTodo.h"
#include "DelTodo.h"
#include "UpdateTodo.h"
#include "FindTodo.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// ������ ������ ���
	int sizeOfTodoList = 0;
	Todo* todoList = new Todo[sizeOfTodoList];

	// ���� ������
	const int sizeMenu = 6;
	const char* menuNames[sizeMenu] = {
		 "1 - �������� ����",
		 "2 - ������� ����",
		 "3 - ������������� ����",
		 "4 - ����� ����",
		 "5 - ����������� ������ ���",
		 "6 - �����"
	};

	ShowTodos(todoList, sizeOfTodoList);
	while (1)
	{
		int selected = ShowMenu(menuNames, sizeMenu);

		switch (selected)
		{
		case 1:
			todoList = AddTodo(todoList, &sizeOfTodoList);
			break;
		case 2:
			DelTodo(todoList, &sizeOfTodoList);
			break;
		case 3:
			UpdateTodo(todoList, sizeOfTodoList);
			break;
		case 4:
			FindTodo(todoList, sizeOfTodoList);
			break;
		case 5:
			ShowTodos(todoList, sizeOfTodoList);
			break;
		}

		if (selected == sizeMenu)
		{
			puts("����� �� ���������...");
			break;
		}
	}
}