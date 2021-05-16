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

	todoList->show();

	// Меню выбора
	Menu* menu = new Menu;
	Todo x;
	
	while (1)
	{
		menu->show(todoList->length());
		int select = menu->getSelect(todoList->length());
		todoList->useSelect(select - 1);
	}
}