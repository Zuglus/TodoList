#pragma once

class Todo
{
	std::string _name;
	enum class Priority {
		low,
		middle,
		high
	};
	Priority _priority;
	std::string _description;
	time_t _date;

public:
	Todo();
	void name(std::string);
	void priority(std::string);
	void description(std::string);
	bool date(tm*);
	std::string name();
	Priority priority();
	std::string priorityString();
	std::string description();
	time_t date();
	tm* localDate();
	void show(int);
};
