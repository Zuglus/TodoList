#pragma once

void ShowTodo(Todo todo, int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "Наименование: " << todo.name << std::endl;
	std::cout << "Приоритет: ";
	GetPriority(todo.priority);
	std::cout << "\nПодробности: " << todo.description;
	std::cout << "\nСрок исполнения: ";
	std::cout << todo.date.tm_mday << '.';
	std::cout << todo.date.tm_mon + 1 << '.';
	std::cout << todo.date.tm_year + 1900;
	std::cout << " к " << todo.date.tm_hour;
	std::cout << ':' << todo.date.tm_min;
	std::cout << std::endl;
}