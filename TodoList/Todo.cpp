// Todo.cpp

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include "Todo.h"

Todo::Todo()
{
	_name = "Новая задача";
	_priority = Priority::low;
	_description = "Описание новой задачи";
	_date = time(NULL) + 3600;
}

void Todo::name(std::string newName)
{
	_name = newName;
}

std::string Todo::name()
{
	return _name;
}

void Todo::priority(int select)
{
	switch (select)
	{
	case 0:
		_priority = Todo::Priority::low;
		break;
	case 1:
		_priority = Todo::Priority::middle;
		break;
	case 2:
		_priority = Todo::Priority::high;
		break;
	}
}

int Todo::priority()
{
	return (int)_priority;
}

std::string Todo::priorityString()
{
	std::string priorityList[3] = {
		"низкий",
		"средний",
		"высокий"
	};

	return priorityList[(int)_priority];
}

void Todo::description(std::string newDescription)
{
	_description = newDescription;
}

std::string Todo::description()
{
	return _description;
}

bool Todo::date(tm* newDate)
{
	time_t tmpTime = mktime(newDate);
	if (tmpTime > time(NULL))
	{
		_date = tmpTime;
		return true;
	}
	return false;
}

time_t Todo::date()
{
	return _date;
}

tm* Todo::localDate()
{
	tm* localDate = new tm;
	localtime_s(localDate, &_date);
	return localDate;
}

void Todo::show(int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "Наименование: " << name() << std::endl;
	std::cout << "Приоритет: " << priorityString() << std::endl;
	std::cout << "Подробности: " << description() << std::endl;
	std::cout << "Срок исполнения: ";
	std::cout << std::setfill('0') << std::setw(2) << localDate()->tm_mday << '.';
	std::cout << std::setfill('0') << std::setw(2) << localDate()->tm_mon + 1 << '.';
	std::cout << localDate()->tm_year + 1900;
	std::cout << " к " << std::setfill('0') << std::setw(2) << localDate()->tm_hour;
	std::cout << ':' << std::setfill('0') << std::setw(2) << localDate()->tm_min;
	std::cout << std::endl;
}