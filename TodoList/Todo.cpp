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
		case low:
			priority = low;
			break;
		case middle:
			priority = middle;
			break;
		case high:
			priority = high;
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

	return priorityList[priority];
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