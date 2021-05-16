#include <iostream>
#include <string>
#include <time.h>
#include "Todo.h"

Todo::Todo()
{
	_name = "����� ������";
	_priority = Priority::low;
	_description = "�������� ����� ������";
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

void Todo::priority(std::string select)
{
	if (select >= "1" &&
		select <= "3")
		switch (std::stoi(select))
		{
		case 1:
			_priority = Priority::low;
			break;
		case 2:
			_priority = Priority::middle;
			break;
		case 3:
			_priority = Priority::high;
			break;
		}
}

Todo::Priority Todo::priority()
{
	return _priority;
}

std::string Todo::priorityString()
{
	std::string priorityList[3] = {
		"������",
		"�������",
		"�������"
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
	if (tmpTime < time(NULL))
		return false;
	_date = tmpTime;
	return true;
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

void Todo::show (int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "������������: " << name() << std::endl;
	std::cout << "���������: " << priorityString() << std::endl;
	std::cout << "�����������: " << description() << std::endl;
	std::cout << "���� ����������: ";
	std::cout << localDate()->tm_mday << '.';
	std::cout << localDate()->tm_mon + 1 << '.';
	std::cout << localDate()->tm_year + 1900;
	std::cout << " � " << localDate()->tm_hour;
	std::cout << ':' << localDate()->tm_min;
	std::cout << std::endl;
}