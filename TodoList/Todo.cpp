#include <iostream>
#include <string>
#include <time.h>
#include "Todo.h"

Todo::Todo()
{
	name = "Новая задача";
	priority = Priority::low;
	description = "Описание новой задачи";
	date = time(NULL) + 3600;
}

void Todo::SetTodoName(std::string newName)
{
		name = newName;
}

std::string Todo::GetTodoName()
{
	return name;
}

void Todo::SetTodoPriority(std::string select)
{
	if (select >= "1" &&
		select <= "3")
		switch (std::stoi(select))
		{
		case 1:
			priority = Priority::low;
			break;
		case 2:
			priority = Priority::middle;
			break;
		case 3:
			priority = Priority::high;
			break;
		}
}

Todo::Priority Todo::GetTodoPriority()
{
	return priority;
}

std::string Todo::GetTodoPriorityString()
{
	std::string priorityList[3] = {
		"низкий",
		"средний",
		"высокий"
	};

	return priorityList[(int)priority];
}

void Todo::SetTodoDescription(std::string newDescription)
{
		description = newDescription;
}

std::string Todo::GetTodoDescription()
{
	return description;
}

bool Todo::SetTodoDate(tm* newDate)
{
	time_t tmpTime = mktime(newDate);
	if (tmpTime < time(NULL))
		return false;
	date = tmpTime;
	return true;
}

time_t Todo::GetTodoDate()
{
	return date;
}

tm* Todo::GetTodoLocalDate()
{
	tm* localDate = new tm;
	localtime_s(localDate, &date);
	return localDate;
}

void Todo::showTodo (int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "Наименование: " << GetTodoName() << std::endl;
	std::cout << "Приоритет: " << GetTodoPriorityString() << std::endl;
	std::cout << "Подробности: " << GetTodoDescription() << std::endl;
	std::cout << "Срок исполнения: ";
	std::cout << GetTodoLocalDate()->tm_mday << '.';
	std::cout << GetTodoLocalDate()->tm_mon + 1 << '.';
	std::cout << GetTodoLocalDate()->tm_year + 1900;
	std::cout << " к " << GetTodoLocalDate()->tm_hour;
	std::cout << ':' << GetTodoLocalDate()->tm_min;
	std::cout << std::endl;
}