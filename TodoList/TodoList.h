#pragma once

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
	void useSelect(int);
private:
	int _length;
	Todo* todoList;
	void(TodoList::** methodsArr)();
};

