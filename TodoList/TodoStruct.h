#pragma once

struct Todo
{
private:
	std::string name;
	enum Priority
	{
		low = 1,
		middle,
		high
	} priority;
	std::string description;
	time_t date;

public:
	Todo()
	{
		name = "Новая задача";
		priority = low;
		description = "Описание новой задачи";
		date = time(NULL) + 3600;
	}

	bool SetTodoName(char* newName)
	{
		if (strlen(newName) > 50)
			return false;
		else
			name = std::string(newName);

		return true;
	}

	std::string GetTodoName()
	{
		return name;
	}

	bool SetTodoPriority(char select)
	{
		if (select < '1' &&
			select > '3')
			return false;
		else
		switch ((int)select)
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

		return true;
	}

	Priority GetTodoPriority()
	{
		return priority;
	}

	std::string GetTodoPriorityString()
	{
		const char* priorityList[3] = {
			"низкий",
			"средний",
			"высокий"
		};

		return priorityList[priority - 1];
	}

	bool SetTodoDescription(char* newDescription)
	{
		if (strlen(newDescription) > 100)
			return false;
		else
			description = std::string(newDescription);

		return true;
	}

	std::string GetTodoDescription()
	{
		return description;
	}

	bool SetTodoDate(tm* newDate)
	{
		time_t tmpTime = mktime(newDate);
		if (tmpTime < time(NULL))
			return false;
		date = tmpTime;
		return true;
	}

	time_t GetTodoDate()
	{
		return date;
	}

	tm* GetTodoLocalDate()
	{
		tm* localDate = new tm;
		localtime_s(localDate, &date);
		return localDate;
	}
};

Todo* x = new Todo;