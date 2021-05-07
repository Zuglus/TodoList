#include <windows.h>
#include <iostream>
#include <string>

#include "Priority.h"
#include "Date.h"
#include "TodoStruct.h"
#include "ConsoleEnter.h"
#include "ShowTodo.h"
#include "ShowTodos.h"
#include "ShowMenu.h"
#include "AddTodo.h"
#include "DelTodo.h"
#include "UpdateTodo.h"
#include "FindTodo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// Массив списка дел
	int sizeOfTodoList = 0;
	Todo* todoList = new Todo[sizeOfTodoList];

	// Меню выбора
	const int sizeMenu = 6;
	const char* menuNames[sizeMenu] = {
		 " - Добавить дело",
		 " - Удалить дело",
		 " - Редактировать дело",
		 " - Поиск дела",
		 " - Отображение списка дел",
		 " - Выход"
	};

	ShowTodos(todoList, sizeOfTodoList);
	while (1)
	{
		int selected = ShowMenu(menuNames, sizeMenu, sizeOfTodoList);

		switch (selected)
		{
		case 1:
			todoList = AddTodo(todoList, &sizeOfTodoList);
			break;
		case 2:
			todoList = DelTodo(todoList, &sizeOfTodoList);
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
			puts("Выход из программы...");
			break;
		}
	}
}