#pragma once

void ShowTodo(Todo todo, int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "Наименование: " << todo.name << std::endl;
	std::cout << "Приоритет: ";
	GetPriority(todo.priority);
	std::cout << "\nПодробности: " << todo.description;
	std::cout << "\nСрок исполнения: ";
	GetDate(todo.date);
	std::cout << " к ";
	GetTime(todo.date);
	std::cout << std::endl;
}