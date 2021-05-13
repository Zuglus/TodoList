#pragma once

class TodoList
{
public:
	TodoList();
	int getListLength();
	void showTodoList();
	void addTodo();
	void deleteTodo();
	void updateTodo();
	void findTodo();
private:
	int listLength;
	Todo* todoList;
};

