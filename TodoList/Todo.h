// Todo.h

#pragma once

class Todo
{
public:
	enum class Priority {
		low,
		middle,
		high
	};
	Todo();
	void name(std::string);
	void priority(int);
	void description(std::string);
	bool date(tm*);
	std::string name();
	int priority();
	std::string priorityString();
	std::string description();
	time_t date();
	tm* localDate();
	void show(int);
private:
	std::string _name;
	Priority _priority;
	std::string _description;
	time_t _date;
};
