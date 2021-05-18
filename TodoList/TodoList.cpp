#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "Todo.h"
#include "TodoList.h"
#include "IsNumber.h"
#include "Menu.h"

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
	std::cout << "\t>>> Список дел: <<<\n";

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
	std::string* s = new std::string;

	system("cls");

	std::cout << "\t\n<<< Создание новой задачи: >>>\n";

	std::cout << "\nЧто нужно сделать?: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo.name(*s);

	std::cout << "Выберите приоритет:\n";
	std::cout << "1. низкий\n";
	std::cout << "2. средний\n";
	std::cout << "3. высокий\n";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo.priority(*s);

	std::cout << "Добавьте подробности: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo.description(*s);
	delete s;

	std::cout << "Введите дату и время исполнения:";
	while (1)
	{
		char tmp[100];
		int tmpInt;
		tm* newDate = new tm;
		*newDate = *newTodo.localDate();

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
	std::string userInput;
	int id;
	while (1)
	{
		getline(std::cin, userInput);
		id = (int)userInput.find_first_of("1234567890");
		if (id >= 0)
		{
			id = userInput[id] - '0';
			if (id <= todoList->size())
				break;
		}
		else
			std::cout << "Ошибочный ввод. Повторите...";
	}

	auto it = todoList->begin();
	todoList->erase(it + id);

	system("cls");

	std::cout << "Дело с ID: " << id << " удалено.\n";
}

void TodoList::update()
{
	system("cls");
	std::cout << " <<< Редактирование задачи >>>\n";
	std::cout << "ID задачи, которую редактируем: ";
	int id;
	std::string userEnter;
	while (1)
	{
		getline(std::cin, userEnter);
		id = (int)userEnter.find_first_of("1234567890");
		if (id >= 0)
		{
			id = userEnter[id] - '0';
			if (id < todoList->size())
				break;
		}
		else
		{
			std::cout << "\nОшибочный ID. Повторите...\n";
		}
	}

	Todo* todo = &todoList->at(id);

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->name() << "): ";

	getline(std::cin, userEnter);
	if (!userEnter.empty())
		todo->name();

	std::cout << "Новый приоритет: " << "(" << todo->priorityString() << "): ";
	getline(std::cin, userEnter);
	if (!userEnter.empty())
		todo->priority(userEnter);

	std::cout << "Новое описание " << "(" << todo->description() << "): ";
	getline(std::cin, userEnter);
	if (!userEnter.empty())
		todo->description(userEnter);
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
		select = menuList->name->size() - 1;
	(this->*menuList->func->at(select))();
}