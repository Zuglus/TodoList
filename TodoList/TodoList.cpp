#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "Todo.h"
#include "TodoList.h"
#include "IsNumber.h"
#include "Menu.h"
#include "Input.h"

TodoList::FindMenu::FindMenu()
{
	name = new std::vector <std::string>{
		" - названию",
		" - приоритету",
		" - описанию",
		" - времени"
	};
	func = new std::vector <void (TodoList::*)()>{
		&TodoList::byName,
		&TodoList::byPriority,
		&TodoList::byDescription,
		&TodoList::byTime
	};
}

TodoList::MenuElement::MenuElement()
{
	name = new std::vector <std::string>{
		" - Добавить дело",
		" - Удалить дело",
		" - Редактировать дело",
		" - Поиск дела",
		" - Отображение списка дел",
		" - Выход"
	};
	func = new std::vector <void (TodoList::*)()>{
		&TodoList::add,
		&TodoList::del,
		&TodoList::update,
		&TodoList::find,
		&TodoList::show,
		&TodoList::exit
	};
}

TodoList::TodoList()
{
	todoList = new std::vector <Todo>;
	menuList = new MenuElement;
}

int TodoList::length()
{
	return (int)todoList->size();
}

void TodoList::show()
{
	system("cls");
	std::cout << "\t>>> Список задач: <<<\n";

	if (!todoList->empty())
		for (int i = 0; i < todoList->size(); ++i)
		{
			(todoList->at(i)).show(i);
		}
	else
		std::cout << "\nДел не запланировано!!!\n";
}
void TodoList::add()
{
	Todo newTodo;

	system("cls");

	std::cout << "\t\n<<< Создание новой задачи: >>>\n";

	std::cout << "\nЧто нужно сделать?: ";
	Input input;
	newTodo.name(input.get(newTodo.name()));

	std::cout << "\nВыберите приоритет:\n";
	newTodo.priority(input.get(newTodo.priority()));

	std::cout << "\nДобавьте подробности: ";
	newTodo.description(input.get(newTodo.description()));

	std::cout << "Введите дату и время исполнения:";
	while (1)
	{
		tm* newDate = new tm;
		*newDate = *newTodo.localDate();
		newDate->tm_min = 0;

		std::cout << "\nДата (" << newDate->tm_mday << "): ";
		newDate->tm_mday = input.get(newDate->tm_mday, 1, 32);

		std::cout << "Месяц (" << newDate->tm_mon + 1 << "): ";
		newDate->tm_mon = input.get(newDate->tm_mon + 1, 1, 13) - 1;

		std::cout << "Год (" << newDate->tm_year + 1900 << "): ";
		newDate->tm_year = input.get(newDate->tm_year + 1900, 1, 3000) - 1900;

		std::cout << "Часы (" << newDate->tm_hour << "): ";
		newDate->tm_hour = input.get(newDate->tm_hour, 0, 24);

		std::cout << "Минуты (" << newDate->tm_min << "): ";
		newDate->tm_min = input.get(newDate->tm_min, 0, 60);

		newDate->tm_sec = 0;

		if (newTodo.date(newDate))
			break;
		std::cout << "Ошибочная дата. Повторите...";
	}

	todoList->push_back(newTodo);

	system("cls");
	std::cout << "\n\t<<<Задача добавлена>>>\n\n";
}
void TodoList::del()
{
	system("cls");
	std::cout << " <<< Удаление одной из задач >>>\n";
	std::cout << "Введите ID: ";
	Input input;
	while(1)
	{
		if (!todoList->empty())
		{
			int id = input.get(-1, 0, todoList->size());
			if (id >= 0)
			{
				auto it = todoList->begin();
				todoList->erase(it + id);
				break;
			}
			else
				std::cout << "Ошибочный ввод. Повторите...";
		}
	}

	system("cls");

	std::cout << "Задача удалена.\n";
}

void TodoList::update()
{
	system("cls");
	std::cout << " <<< Редактирование задачи >>>\n";
	std::cout << "ID задачи, которую редактируем: ";
	Input input;
	int id{ -1 };
	while (1)
	{
		if (!todoList->empty())
		{
			int id = input.get(-1, 0, todoList->size());
			if (id >= 0)
				break;
			else
				std::cout << "Ошибочный ввод. Повторите...";
		}
	}

	Todo* todo = &todoList->at(id);

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->name() << "): ";
	todo->name(input.get(todo->name()));

	std::cout << "Новый приоритет: " << "(" << todo->priorityString() << "): ";
	todo->priority(input.get(todo->priority()));

	std::cout << "Новое описание " << "(" << todo->description() << "): ";
	todo->description(input.get(todo->description()));

	std::cout << "Новая дата: ";

}

void TodoList::find()
{
	system("cls");
	std::cout << "\t<<< Поиск дел по: >>>\n";
	Menu findMenu;
	FindMenu findList;
	findMenu.show(true, *findList.name);
	int select = findMenu.getSelect("1234");
	(this->*findList.func->at(select - 1))();
}

void TodoList::byName()
{
	std::cout << "По какому имени искать?\n--> ";
	std::string toFind;
	getline(std::cin, toFind);

	std::cout << "\nИщем...\n";
	bool isExist = false;
	int* count = new int(0);
	for (auto i : *todoList)
	{
		
		int pos = (int)i.name().find(toFind);
		if (pos >= 0)
		{
			i.show(*count);
			isExist = true;
		}
		++*count;
	}
	delete count;

	if (!isExist)
	{
		system("cls");
		std::cout << "По этому имени нет данных\n";
	}
}

void TodoList::byPriority()
{
	std::cout << "byPrir";
}

void TodoList::byDescription()
{
	std::cout << "Что ищем?\n--> ";
	std::string toFind;
	getline(std::cin, toFind);

	std::cout << "\nИщем...\n";
	bool isExist = false;
	int* count = new int(0);
	for (auto i : *todoList)
	{

		int pos = (int)i.description().find(toFind);
		if (pos >= 0)
		{
			i.show(*count);
			isExist = true;
		}
		++* count;
	}
	delete count;

	if (!isExist)
	{
		system("cls");
		std::cout << "По этому описанию нет данных\n";
	}
}
void TodoList::byTime(){}

void TodoList::exit()
{
	system("cls");
	std::cout << "\nОсуществляется выход...\n";
	std::exit(0);
}

void TodoList::useSelect(int select)
{
	if (todoList->empty() &&
		select == 1)
		select = (int)menuList->name->size() - 1;
	(this->*menuList->func->at(select))();
}