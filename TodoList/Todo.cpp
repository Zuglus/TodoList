#include <iostream>
#include "TodoStruct.h"
#include "ShowTodos.h"
#include "ShowMenu.h"
#include "AddTodo.h"
#include "DelTodo.h"
#include "UpdateTodo.h"
#include "FindTodo.h"

using namespace std;

int main()
{
	setlocale(NULL, "Ru");

	// ������ ������ ���
	int sizeOfTodoList = 0;
	Todo* todoList = new Todo[sizeOfTodoList];

	// ���� ������
	const int sizeMenu = 6;
	void(*menu[sizeMenu - 1])(Todo*, int) = { AddTodo, DelTodo, UpdateTodo, FindTodo, ShowTodos };
	const char* menuNames[sizeMenu] = {
		 "1 - �������� ����",
		 "2 - ������� ����",
		 "3 - ������������� ����",
		 "4 - ����� ����",
		 "5 - ����������� ������ ���",
		 "6 - �����"
	};

	ShowTodos(todoList, sizeOfTodoList);
	ShowMenu(menu, menuNames, sizeMenu, todoList, sizeOfTodoList);
}