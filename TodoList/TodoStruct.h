#pragma once

struct Todo
{
	std::string name;
	Priority priority;
	std::string description;
	tm date;
	Todo()
	{
		name = "Новая задача";
		priority = low;
		description = "Описание новой задачи";
		time_t now = time(NULL);
		tm* tmpTime = new tm;
		localtime_s(tmpTime, &now);
		date = *tmpTime;
		date.tm_hour++;
	}
};