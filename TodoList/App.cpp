#include <windows.h>
#include <iostream>
#include <string>

#include "Todo.h"
#include "TodoList.h"
#include "Menu.h"
#include "IsNumber.h"
#include "DelTodo.h"
#include "UpdateTodo.h"
#include "FindTodo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// Массив списка дел
	TodoList* todoList = new TodoList;

	todoList->showTodoList();

	// Меню выбора
	Menu* menu = new Menu;
	
	while (1)
	{
		menu->show(todoList->getListLength());
		int select = menu->getSelect(todoList->getListLength());

		switch (select)
		{
		case 1:
			todoList->addTodo();
			break;
		case 5:
			todoList->showTodoList();
			break;
		}
	}
}