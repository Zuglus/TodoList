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
	setlocale(NULL, "Ru");

	// Массив списка дел
	int sizeOfTodoList = 0;
	Todo* todoList = new Todo[sizeOfTodoList];

	// Меню выбора
	const int sizeMenu = 6;
	void(*menu[sizeMenu - 1])(Todo*, int) = { AddTodo, DelTodo, UpdateTodo, FindTodo, ShowTodos };
	const char* menuNames[sizeMenu] = {
		 "1 - Добавить дело",
		 "2 - Удалить дело",
		 "3 - Редактировать дело",
		 "4 - Поиск дела",
		 "5 - Отображение списка дел",
		 "6 - Выход"
	};

	ShowTodos(todoList, sizeOfTodoList);
	ShowMenu(menu, menuNames, sizeMenu, todoList, sizeOfTodoList);
}