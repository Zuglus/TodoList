#include <iostream>
#include <string>
#include <Windows.h>
#include "Todo.h"
#include "TodoList.h"
#include "IsNumber.h"

TodoList::TodoList()
{
	listLength = 0;
	todoList = new Todo[listLength];
}

int TodoList::getListLength()
{
	return listLength;
}

void TodoList::showTodoList()
{
	system("cls");
	std::cout << "\t>>> Список дел: <<<\n";

	if (listLength)
		for (int i = 0; i < listLength; ++i)
		{
			todoList[i].showTodo(i);
		}
	else
		std::cout << "\nДел не запланировано!!!\n";
}
void TodoList::addTodo()
{
	listLength++;
	Todo* newList = new Todo[listLength];

	for (int i = 0; i < listLength - 1; ++i)
		newList[i] = todoList[i];

	delete[]todoList;
	todoList = newList;

	newList = nullptr;

	Todo* newTodo = new Todo;
	std::string* s = new std::string;

	system("cls");

	std::cout << "\t\n<<< Создание новой задачи: >>>\n";

	std::cout << "\nЧто нужно сделать?: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->SetTodoName(*s);

	std::cout << "Выберите приоритет:\n";
	std::cout << "1. низкий\n";
	std::cout << "2. средний\n";
	std::cout << "3. высокий\n";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->SetTodoPriority(*s);

	std::cout << "Добавьте подробности: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->SetTodoDescription(*s);
	delete s;

	std::cout << "Введите дату и время исполнения:";
	while (1)
	{
		char tmp[100];
		int tmpInt;
		tm* newDate = new tm;
		*newDate = *newTodo->GetTodoLocalDate();

		std::cout << "\nДата (" << newDate->tm_mday << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 31)
				newDate->tm_mday = tmpInt;
		}

		std::cout << "Месяц (" << newDate->tm_mon + 1 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 12)
				newDate->tm_mon = tmpInt - 1;
		}

		std::cout << "Год (" << newDate->tm_year + 1900 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			IsNumber(tmp))
		{
			newDate->tm_year = atoi(tmp);
		}

		std::cout << "Часы (" << newDate->tm_hour << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 23)
				newDate->tm_hour = tmpInt;
		}

		std::cout << "Минуты (" << newDate->tm_min << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt < 60)
				newDate->tm_min = tmpInt;
		}

		newDate->tm_sec = 0;

		if (newTodo->SetTodoDate(newDate))
			break;
		std::cout << "Ошибочная дата. Повторите...";
	}

	todoList[listLength - 1] = *newTodo;

	system("cls");
	std::cout << "\n\t<<<Задача добавлена>>>\n\n";
}
void TodoList::deleteTodo(){}
void TodoList::updateTodo(){}
void TodoList::findTodo(){}

	