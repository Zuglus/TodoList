#include <iostream>
#include <string>
#include <Windows.h>
#include "Todo.h"
#include "TodoList.h"
#include "IsNumber.h"

TodoList::TodoList()
{
	_length = 0;
	todoList = new Todo[_length];
	methodsArr = new (void(TodoList:: * [5])()){
	&TodoList::add,
	&TodoList::del,
	&TodoList::update,
	&TodoList::find,
	&TodoList::show
	};
}

void TodoList::useSelect(int select)
{
	(this->*methodsArr[select])();
}

int TodoList::length()
{
	return _length;
}

void TodoList::show()
{
	system("cls");
	std::cout << "\t>>> ������ ���: <<<\n";

	if (_length)
		for (int i = 0; i < _length; ++i)
		{
			todoList[i].show(i);
		}
	else
		std::cout << "\n��� �� �������������!!!\n";
}
void TodoList::add()
{
	Todo* newList = new Todo[++_length];

	for (int i = 0; i < _length - 1; ++i)
		newList[i] = todoList[i];

	delete[]todoList;
	todoList = newList;

	newList = nullptr;

	Todo* newTodo = new Todo;
	std::string* s = new std::string;

	system("cls");

	std::cout << "\t\n<<< �������� ����� ������: >>>\n";

	std::cout << "\n��� ����� �������?: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->name(*s);

	std::cout << "�������� ���������:\n";
	std::cout << "1. ������\n";
	std::cout << "2. �������\n";
	std::cout << "3. �������\n";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->priority(*s);

	std::cout << "�������� �����������: ";
	getline(std::cin, *s);
	if (!s->empty())
		newTodo->description(*s);
	delete s;

	std::cout << "������� ���� � ����� ����������:";
	while (1)
	{
		char tmp[100];
		int tmpInt;
		tm* newDate = new tm;
		*newDate = *newTodo->localDate();

		std::cout << "\n���� (" << newDate->tm_mday << "): ";
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

		std::cout << "����� (" << newDate->tm_mon + 1 << "): ";
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

		std::cout << "��� (" << newDate->tm_year + 1900 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			IsNumber(tmp))
		{
			newDate->tm_year = atoi(tmp);
		}

		std::cout << "���� (" << newDate->tm_hour << "): ";
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

		std::cout << "������ (" << newDate->tm_min << "): ";
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

		if (newTodo->date(newDate))
			break;
		std::cout << "��������� ����. ���������...";
	}

	todoList[_length - 1] = *newTodo;

	system("cls");
	std::cout << "\n\t<<<������ ���������>>>\n\n";
}
void TodoList::del()
{
	Todo* newArr = new Todo[--_length];

	system("cls");
	std::cout << " <<< �������� ����� �� ����� >>>\n";
	std::cout << "������� ID: ";
	std::string userInput;
	int id;
	while (1)
	{
		getline(std::cin, userInput);
		id = (int)userInput.find_first_of("1234567890");
		if (id >= 0)
		{
			id = userInput[id] - '0';
			if (id <= _length)
				break;
		}
		else
			std::cout << "��������� ����. ���������...";
	}

	for (int i = 0; i < _length; ++i)
	{
		if (i < id)
			newArr[i] = todoList[i];
		else
			newArr[i] = todoList[i + 1];
	}

	system("cls");

	std::cout << "���� � ID: " << id << " �������.\n";

	delete[]todoList;
	todoList = newArr;
}

void TodoList::update(){}
void TodoList::find(){}

	