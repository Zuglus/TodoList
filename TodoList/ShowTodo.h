#pragma once

void ShowTodo(Todo todo, int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "Наименование: " << todo.GetTodoName() << std::endl;
	std::cout << "Приоритет: " << todo.GetTodoPriorityString() << std::endl;
	std::cout << "Подробности: " << todo.GetTodoDescription() << std::endl;
	std::cout << "Срок исполнения: ";
	std::cout << todo.GetTodoLocalDate()->tm_mday << '.';
	std::cout << todo.GetTodoLocalDate()->tm_mon + 1 << '.';
	std::cout << todo.GetTodoLocalDate()->tm_year + 1900;
	std::cout << " к " << todo.GetTodoLocalDate()->tm_hour;
	std::cout << ':' << todo.GetTodoLocalDate()->tm_min;
	std::cout << std::endl;
}