#pragma once

void ShowTodo(Todo todo, int id)
{
	std::cout << "\nID: " << id << std::endl;
	std::cout << "������������: " << todo.name << std::endl;
	std::cout << "���������: ";
	GetPriority(todo.priority);
	std::cout << "\n�����������: " << todo.description;
	std::cout << "\n���� ����������: ";
	GetDate(todo.date);
	std::cout << " � ";
	GetTime(todo.date);
	std::cout << std::endl;
}