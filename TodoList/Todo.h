#pragma once

class Todo
{
	std::string name;
	enum Priority
	{
	low,
	middle,
	high
	} priority;
	std::string description;
	time_t date;

public:
	Todo();
	void SetTodoName(std::string);
	void SetTodoPriority(std::string);
	void SetTodoDescription(std::string);
	bool SetTodoDate(tm*);
	std::string GetTodoName();
	Priority GetTodoPriority();
	std::string GetTodoPriorityString();
	std::string GetTodoDescription();
	time_t GetTodoDate();
	tm* GetTodoLocalDate();	
};
