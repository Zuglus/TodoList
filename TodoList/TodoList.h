// TodoList.h

#pragma once

#include "Todo.h"

class TodoList
{
public:
	TodoList();
	int length();
	void show();
	void add();
	void del();
	void update();
	void find();
	void exit();
	void useSelect(int);

	class FindMenu
	{
	public:
		FindMenu();
		std::vector <std::string>* name;
		std::vector <void(TodoList::*)()>* func;
	};
	class MenuElement
	{
	public:
		MenuElement();
		std::vector <std::string>* name;
		std::vector <void(TodoList::*)()>* func;
	};
	MenuElement* menuList;
private:
	std::vector <Todo>* todoList;
	void byName();
	void byPriority();
	void byDescription();
	void byTime();
};

