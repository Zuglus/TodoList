// App.cpp

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

#include "Todo.h"
#include "TodoList.h"
#include "Menu.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// Массив списка дел
	TodoList* todolist = new TodoList;

	todolist->show();

	// Меню выбора
	Menu* menu = new Menu;

	while (1)
	{
		std::cout << "\n\t<<< Меню: >>>\n\n";
		menu->show(todolist->length(), *todolist->menuList->name);
		int select = menu->getSelect("123456");
		todolist->useSelect(select - 1);
	}
}